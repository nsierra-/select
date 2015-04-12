#include "ftlst.h"

void					*lst_remove(t_lst *lst, size_t pos)
{
	t_lstelem			*cursor;
	size_t				i;

	if (pos >= lst_get_size(lst))
		return (0);
	i = 0;
	cursor = lst_elem_front(lst);
	if (cursor == lst_elem_back(lst))
		lst->first = NULL;
	while (i++ < pos)
		cursor = cursor->next;
	--lst->size;
	return (elem_destroy(&cursor));
}
