#include "ftlst.h"

t_lstelem		*lst_elem_at(t_lst *lst, size_t pos)
{
	t_lstelem	*cursor;
	size_t		i;

	if (pos >= lst_get_size(lst))
		return (NULL);
	i = 0;
	cursor = lst_elem_front(lst);
	while (i++ < pos)
		cursor = cursor->next;
	return (cursor);
}
