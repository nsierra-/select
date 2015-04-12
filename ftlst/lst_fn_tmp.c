#include "ftlst.h"
#include "libft.h"
#include <stdlib.h>

t_lstelem				*new_lstelem(void *data)
{
	t_lstelem			*new_elem;

	if (!(new_elem = malloc(sizeof(t_lstelem))))
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

t_lst					*new_lst(void)
{
	t_lst				*new_list;

	if (!(new_list = malloc(sizeof(t_lst))))
		return (NULL);
	new_list->size = 0;
	new_list->first = NULL;
	return (new_list);
}

void					elem_insert_between(t_lstelem *to_insert, t_lstelem *before, t_lstelem *after)
{
	if (before == after)
	{
		after->prev = to_insert;
		after->next = to_insert;
		to_insert->prev = after;
		to_insert->next = after;
	}
	else
	{
		to_insert->prev = before;
		to_insert->next = after;
		before->next = to_insert;
		after->prev = to_insert;
	}
}

void					elem_swap(t_lstelem *elem1, t_lstelem *elem2)
{
	void				*tmp;

	tmp = elem1->data;
	elem1->data = elem2->data;
	elem2->data = tmp;
}

void					*elem_destroy(t_lstelem **elem)
{
	t_lstelem			*elem_;
	t_lstelem			*left;
	t_lstelem			*right;
	void				*ret;

	elem_ = *elem;
	if (!(elem_->next == elem_))
	{
		left = elem_->prev;
		right = elem_->next;
		left->next = right;
		right->prev = left;
	}
	ret = elem_->data;
	free(elem_);
	*elem = NULL;
	return (ret);
}

size_t					lst_get_size(t_lst *lst)
{
	return (lst->size);
}

int						lst_is_empty(t_lst *lst)
{
	return (lst->first == NULL ? 1 : 0);
}

t_lstelem				*lst_elem_at(t_lst *lst, size_t pos)
{
	t_lstelem			*cursor;
	size_t				i;

	if (pos >= lst_get_size(lst))
		return (NULL);
	i = 0;
	cursor = lst_elem_front(lst);
	while (i++ < pos)
		cursor = cursor->next;
	return (cursor);
}

void					*lst_data_at(t_lst *lst, size_t pos)
{
	return (lst_elem_at(lst, pos)->data);
}

t_lstelem				*lst_elem_front(t_lst *lst)
{
	return (lst_is_empty(lst) ? NULL : lst->first);
}

t_lstelem				*lst_elem_back(t_lst *lst)
{
	return (lst_is_empty(lst) ? NULL : lst->first->prev);
}

void					*lst_data_front(t_lst *lst)
{
	return (lst_is_empty(lst) ? NULL : lst_elem_front(lst)->data);
}

void					*lst_data_back(t_lst *lst)
{
	return (lst_is_empty(lst) ? NULL : lst_elem_back(lst)->data);
}

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

int						lst_push_front(t_lst *lst, void *data)
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
	lst->first = new_elem;
	return (++lst->size);
}

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

int						lst_insert(t_lst *lst, void *data, size_t pos)
{
	t_lstelem			*cursor;
	size_t				i;

	if (lst_is_empty(lst) || pos == 0)
		return (lst_push_front(lst, data));
	if (pos >= lst_get_size(lst))
		return (0);
	i = 0;
	cursor = lst_elem_front(lst);
	while (i++ < pos)
		cursor = cursor->next;
	elem_insert_between(new_lstelem(data), cursor->prev, cursor);
	return (++lst->size);
}

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

void					lst_del(t_lst *lst, size_t pos)
{
	void				*data;

	if ((data = lst_remove(lst, pos)))
		free(data);
}

void					lst_swap(t_lst *lst, size_t pos1, size_t pos2)
{
	t_lstelem			*cursor1;
	t_lstelem			*cursor2;
	size_t				i;

	if (pos1 >= lst_get_size(lst) || pos2 >= lst_get_size(lst) || pos1 == pos2)
		return ;
	i = 0;
	cursor1 = lst_elem_front(lst);
	while (i++ < pos1)
		cursor1 = cursor1->next;
	i = 0;
	cursor2 = lst_elem_front(lst);
	while (i++ < pos2)
		cursor2 = cursor2->next;
	elem_swap(cursor1, cursor2);
}

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

void					lst_print(t_lst *lst, void (*print_f)(void *), int mode)
{
	t_lstelem			*cursor;
	size_t				i;
	size_t				lsize;

	cursor = lst_elem_front(lst);
	i = 0;
	lsize = lst_get_size(lst);
	while (i++ < lsize)
	{
		ft_putendl("----------");
		if (mode == 1)
		{
			ft_putstr("Position : ");
			ft_putnbr((int)(i - 1));
			ft_putstr("\nData : ");
		}			
		print_f(cursor->data);
		ft_putendl("\n----------");
		cursor = cursor->next;
	}
	ft_putstr("Total size : ");
	ft_putnbr(lst_get_size(lst));
	ft_putendl("");
}

void					lst_clear(t_lst *lst)
{
	while (lst_pop_back(lst))
		;
}

void					lst_destroy(t_lst **lst)
{
	void				*data;
	t_lst				*list;

	list = *lst;
	while ((data = lst_pop_back(list)))
		free(data);
	free(list);
	*lst = NULL;
}
