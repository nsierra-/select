#include "ftlst.h"

t_lstelem				*lst_elem_back(t_lst *lst)
{
	return (lst_is_empty(lst) ? NULL : lst->first->prev);
}
