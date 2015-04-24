#include "ft_select.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <sys/ioctl.h>

static void			send_suspend_signal(void)
{
	struct termios	g_dat;
	char			cp[2];

	if (tcgetattr(0, &g_dat) == -1)
		return ;
	cp[0] = g_dat.c_cc[VSUSP];
	cp[1] = 0;
	ioctl(0, TIOCSTI, cp);
}

static void			resize_sig()
{
	t_env			*e;
	char			*name_term;

	e = get_env();
	if (!(name_term = getenv("TERM")))
		return ;
	if (tgetent(NULL, name_term) != 1)
		return ;
	e->l = tgetnum("li");
	e->c = tgetnum("co");
}

void				signal_handler(int sig)
{
	if (sig == SIGINT)
		exit(exit_ftselect(sig) + 128);
	else if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		signal(SIGCONT, signal_handler);
		restore_termcaps();
		send_suspend_signal();
	}
	else if (sig == SIGCONT)
	{
		signal(SIGTSTP, signal_handler);
		init_termcaps();
	}
	else if (sig == SIGWINCH)
		resize_sig();
}
