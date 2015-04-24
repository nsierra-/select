#include "ft_select.h"
#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <stdio.h>

void				restore_termcaps(void)
{
	t_env			*e;

	e = get_env();
	tputs(tgetstr("cl", NULL), 1, ft_putrchar);
	tputs(tgetstr("te", NULL), 1, ft_putrchar);
	tputs(tgetstr("ve", NULL), 1, ft_putrchar);
	e->term.c_cc[VMIN] = 1;
	e->term.c_cc[VTIME] = 0;
	if (tcsetattr(isatty(STDOUT_FILENO), TCSADRAIN, &e->term) == -1)
		return ;
}