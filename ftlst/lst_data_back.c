#include "ftlst.h"

void	*lst_data_back(t_lst *lst)
{
	return (lst_is_empty(lst) ? NULL : lst_elem_back(lst)->data);
}
