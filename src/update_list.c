#include "ft_select.h"
#include <stdlib.h>

static void		move_up(t_env *e)
{
	t_lstiter	*it;
	t_lstelem	*elem;
	t_el		*data;

	it = new_lstiter(e->lst, increasing);
	while (lst_iterator_next(it))
	{
		elem = (t_lstelem *)it->current;
		data = (t_el *)it->data;
		if (data->current)
		{
			data->current = 0;
			data = elem->prev->data;
			data->current = 1;
			free(it);
			return ;
		}
	}
	free(it);
}

static void		move_down(t_env *e)
{
	t_lstiter	*it;
	t_lstelem	*elem;
	t_el		*data;

	it = new_lstiter(e->lst, increasing);
	while (lst_iterator_next(it))
	{
		elem = (t_lstelem *)it->current;
		data = (t_el *)it->data;
		if (data->current)
		{
			data->current = 0;
			data = elem->next->data;
			data->current = 1;
			free(it);
			return ;
		}
	}
	free(it);
}

static void		selection(t_env *e)
{
	t_lstiter	*it;
	t_lstelem	*elem;
	t_el		*data;

	it = new_lstiter(e->lst, increasing);
	while (lst_iterator_next(it))
	{
		elem = (t_lstelem *)it->current;
		data = (t_el *)it->data;
		if (data->current)
		{
			data->current = 0;
			data->selected = !data->selected;
			data = elem->next->data;
			data->current = 1;
			free(it);
			return ;
		}
	}
	free(it);
}

static void		delete_one(t_env *e)
{
	t_lstiter	*it;
	t_lstelem	*elem;
	t_el		*data;

	it = new_lstiter(e->lst, increasing);
	while (lst_iterator_next(it))
	{
		elem = (t_lstelem *)it->current;
		data = (t_el *)it->data;
		if (data->current)
		{
			data = elem->next->data;
			data->current = 1;
			lst_remove(e->lst, it->pos);
			free(it);
			return ;
		}
	}
	free(it);
}

int				update_list(t_env *e, const char *buf)
{
	if (buf[0] == 27 && buf[2] == 66)
		move_down(e);
	else if (buf[0] == 27 && buf[2] == 65)
		move_up(e);
	else if (buf[0] == 4)
		exit(exit_ftselect(EXIT_SUCCESS));
	else if (buf[0] == 27 && buf[1] == 0)
		exit(exit_ftselect(EXIT_SUCCESS));
	else if (buf[0] == 32)
		selection(e);
	else if (buf[0] == 127 || BS)
		delete_one(e);
	else if ((buf[0] == 10 && buf[1] == 0) || lst_is_empty(e->lst))
		return (0);
	return (1);
}
