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
}
