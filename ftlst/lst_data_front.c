#include "ftlst.h"

void	*lst_data_front(t_lst *lst)
{
	return (lst_is_empty(lst) ? NULL : lst_elem_front(lst)->data);
}
