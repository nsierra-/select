#include "ftlst.h"

int						lst_push_back(t_lst *lst, void *data)
{
	t_lstelem			*new_elem;

	if (!(new_elem = new_lstelem(data)))
		return (0);
	else if (lst_is_empty(lst))
	{
		new_elem->prev = new_elem;
		new_elem->next = new_elem;
		lst->first = new_elem;
		return (++lst->size);
	}
	elem_insert_between(new_elem, lst_elem_back(lst), lst_elem_front(lst));
	return (++lst->size);
}
