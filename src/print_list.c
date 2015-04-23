#include "ft_select.h"
#include "libft.h"
#include <term.h>
#include <stdlib.h>
#include <unistd.h>

static void		init_printing(t_vector *cur)
{
	cur->x = 0;
	cur->y = 0;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putrchar);
	tputs(tgetstr("cd", NULL), 1, ft_putrchar);
}

void			normal_mode(t_env *e, t_el *data)
{
	ft_putstr_fd(data->word, e->term_fd);
}

void			selected_mode(t_env *e, t_el *data)
{
	tputs(tgetstr("mr", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, e->term_fd);
	tputs(tgetstr("me", NULL), 1, ft_putrchar);
}

void			current_mode(t_env *e, t_el *data)
{
	tputs(tgetstr("us", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, e->term_fd);
	tputs(tgetstr("ue", NULL), 1, ft_putrchar);
}

void			hardcore_mode(t_env *e, t_el *data)
{
	tputs(tgetstr("us", NULL), 1, ft_putrchar);
	tputs(tgetstr("mr", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, e->term_fd);
	tputs(tgetstr("ue", NULL), 1, ft_putrchar);
	tputs(tgetstr("me", NULL), 1, ft_putrchar);
}

static void		chose_mode(t_env *e, t_el *data)
{
	if (data->current && data->selected)
		hardcore_mode(e, data);
	else if (data->current)
		current_mode(e, data);
	else if (data->selected)
		selected_mode(e, data);
	else
		normal_mode(e, data);
}

static void		print_word(t_env *e, t_el *data, t_vector *cur)
{
	chose_mode(e, data);
	++cur->y;
	tputs(tgoto(tgetstr("cm", NULL), cur->x, cur->y), 1, ft_putrchar);
}

void			print_list(t_env *e)
{
	t_vector	cur;
	t_lstiter	*it;

	init_printing(&cur);
	it = new_lstiter(e->lst, increasing);
	while (lst_iterator_next(it))
		print_word(e, (t_el *)it->data, &cur);
	free(it);
}