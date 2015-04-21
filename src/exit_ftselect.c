#include "ft_select.h"

int				exit_ftselect(int ret)
{
	t_lst		*lst;

	lst = get_env()->lst;
	lst_destroy(&lst, delete_element);
	restore_termcaps();
	return (ret);
}