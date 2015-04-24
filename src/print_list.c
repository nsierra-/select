/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 16:25:14 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/24 16:25:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void		print_word(t_env *e, t_el *data, t_vector *cur, size_t *max)
{
	size_t		s;

	s = ft_strlen(data->word);
	*max = s > *max ? s : *max;
	chose_mode(e, data);
	++cur->y;
	if (cur->y >= e->l)
	{
		cur->y = 0;
		cur->x += *max + 2;
		*max = 0;
	}
	tputs(tgoto(tgetstr("cm", NULL), cur->x, cur->y), 1, ft_putrchar);
}

void			print_list(t_env *e)
{
	t_vector	cur;
	t_lstiter	*it;
	size_t		max_word;

	init_printing(&cur);
	max_word = 0;
	it = new_lstiter(e->lst, increasing);
	while (lst_iterator_next(it))
		print_word(e, (t_el *)it->data, &cur, &max_word);
	free(it);
}
