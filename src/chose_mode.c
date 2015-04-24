/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 16:24:59 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/24 16:25:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <term.h>
#include <unistd.h>

static void			normal_mode(t_env *e, t_el *data)
{
	(void)e;
	ft_putstr_fd(data->word, isatty(STDOUT_FILENO));
}

static void			selected_mode(t_env *e, t_el *data)
{
	(void)e;
	tputs(tgetstr("mr", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, isatty(STDOUT_FILENO));
	tputs(tgetstr("me", NULL), 1, ft_putrchar);
}

static void			current_mode(t_env *e, t_el *data)
{
	(void)e;
	tputs(tgetstr("us", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, isatty(STDOUT_FILENO));
	tputs(tgetstr("ue", NULL), 1, ft_putrchar);
}

static void			hardcore_mode(t_env *e, t_el *data)
{
	(void)e;
	tputs(tgetstr("us", NULL), 1, ft_putrchar);
	tputs(tgetstr("mr", NULL), 1, ft_putrchar);
	ft_putstr_fd(data->word, isatty(STDOUT_FILENO));
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
