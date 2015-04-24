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
	if (e->term_fd != -1)
		return (0);
	if (!(name_term = getenv("TERM")))
		return (0);
	tgetent(NULL, name_term);
	tcgetattr(0, &e->term);
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_cc[VMIN] = 0;
	e->term.c_cc[VTIME] = 1;
	if (tcsetattr(isatty(STDOUT_FILENO), TCSADRAIN, &e->term) == -1)
	{
		dprintf(2, "Damn.");
		return (-1);
	}
	dprintf(2, "TEST");
	tputs(tgetstr("ti", NULL), 1, ft_putrchar);
	tputs(tgetstr("vi", NULL), 1, ft_putrchar);
	return (1);
}