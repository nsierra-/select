#include "ftlst.h"

void		elem_swap(t_lstelem *elem1, t_lstelem *elem2)
{
	void	*tmp;

	tmp = elem1->data;
	elem1->data = elem2->data;
	elem2->data = tmp;
}
