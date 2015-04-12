#include "ftlst.h"

int	lst_is_empty(t_lst *lst)
{
	return (lst->first == NULL ? 1 : 0);
}
