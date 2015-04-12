/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iterator_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 09:11:16 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 09:11:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

static void	has_ended_or_skip(t_lstiter *it)
{
	if (!it->flag)
		it->flag = 1;
	else
	{
		it->current = NULL;
		it->data = NULL;
		it->end = NULL;
		it->dir = end;
	}
}

int			lst_iterator_next(t_lstiter *it)
{
	it->current = it->dir == increasing ? it->current->next : it->current->prev;
	it->data = it->current->data;
	if (it->current == it->end)
		has_ended_or_skip(it);
	return (it->dir == end ? 0 : 1);
}
