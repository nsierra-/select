#include "ft_select.h"
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int					init_termcaps(void)
{
	t_env			*e;
	char			*name_term;

	e = get_env();
	if (!(name_term = getenv("TERM")))
		return (0);
	if (tgetent(NULL, name_term) != 1)
		return (0);
	if (tcgetattr(0, &e->term) == -1)
		return (0);
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_cc[VMIN] = 0;
	e->term.c_cc[VTIME] = 1;
	e->l = tgetnum("li");
	e->c = tgetnum("co");
	if (tcsetattr(isatty(STDOUT_FILENO), TCSADRAIN, &e->term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_putrchar);
	tputs(tgetstr("vi", NULL), 1, ft_putrchar);
	return (1);
}