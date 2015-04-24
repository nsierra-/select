#include "ft_select.h"
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static int			stdstream_check(t_env *e)
{
	if (isatty(STDOUT_FILENO))
		return (e->term_fd = isatty(STDOUT_FILENO));
	else
		return (ENOTTY);
}

int					init_termcaps(void)
{
	t_env			*e;
	char			*name_term;
	int				ret;

	e = get_env();
	if (e->term_fd != -1)
		return (0);
	if (!(name_term = getenv("TERM")))
		return (0);
	tgetent(NULL, name_term);
	tcgetattr(0, &e->term);
	if ((ret = stdstream_check(e)) == ENOTTY)
		return (ret);
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_cc[VMIN] = 0;
	e->term.c_cc[VTIME] = 1;
	if (tcsetattr(e->term_fd, TCSADRAIN, &e->term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_putrchar);
	tputs(tgetstr("vi", NULL), 1, ft_putrchar);
	return (1);
}