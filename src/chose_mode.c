#include "ft_select.h"
#include "libft.h"
#include <term.h>

static void			normal_mode(t_env *e, t_el *data)
{
	ft_putstr_fd(data->word, e->term_fd);
}

static void			selected_mode(t_env *e, t_el *data)
{
	tputs(tgetstr("mr", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, e->term_fd);
	tputs(tgetstr("me", NULL), 1, ft_putrchar);
}

static void			current_mode(t_env *e, t_el *data)
{
	tputs(tgetstr("us", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, e->term_fd);
	tputs(tgetstr("ue", NULL), 1, ft_putrchar);
}

static void			hardcore_mode(t_env *e, t_el *data)
{
	tputs(tgetstr("us", NULL), 1, ft_putrchar);
	tputs(tgetstr("mr", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, e->term_fd);
	tputs(tgetstr("ue", NULL), 1, ft_putrchar);
	tputs(tgetstr("me", NULL), 1, ft_putrchar);
}

void				chose_mode(t_env *e, t_el *data)
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