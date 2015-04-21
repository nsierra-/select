#include "ft_select.h"
#include <termios.h>
#include <term.h>

void				restore_termcaps(void)
{
	t_env			*e;

	e = get_env();
	if (e->term_fd != -1)
	{
		tputs(tgetstr("te", NULL), 1, ft_putrchar);
    	tputs(tgetstr("ve", NULL), 1, ft_putrchar);
    	e->term_fd = -1;
	}
}