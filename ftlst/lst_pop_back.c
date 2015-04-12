#include "ftlst.h"

void					*lst_pop_back(t_lst *lst)
{
	t_lstelem			*last;

	if (lst->first == NULL)
		return (NULL);
	last = lst_elem_back(lst);
	if (last == lst_elem_front(lst))
		lst->first = NULL;
	--lst->size;
	return (elem_destroy(&last));
}
