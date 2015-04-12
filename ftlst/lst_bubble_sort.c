#include "ftlst.h"

void					lst_bubble_sort(t_lst *lst, int (*cmp)(void *, void *))
{
	int					sorted;
	t_lstelem			*cursor;


	sorted = 0;
	if (lst_get_size(lst) == 1)
		return ;
	while (!sorted)
	{
		cursor = lst_elem_front(lst);
		sorted = 1;
		while (42)
		{
			if (cursor->next == lst_elem_front(lst))
				break ;
			if (cmp(cursor->data, cursor->next->data) > 0)
			{
				elem_swap(cursor, cursor->next);
				sorted = 0;
			}
			cursor = cursor->next;
		}
	}
}
