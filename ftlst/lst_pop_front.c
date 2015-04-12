#include "ftlst.h"

void					*lst_pop_front(t_lst *lst)
{
	t_lstelem			*first;

	if (lst->first == NULL)
		return (NULL);
	first = lst_elem_front(lst);
	if (first == lst_elem_back(lst))
		lst->first = NULL;
	else
		lst->first = first->next;
	--lst->size;
	return (elem_destroy(&first));
}
