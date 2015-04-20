/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 09:11:27 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 09:11:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"
#include <stdlib.h>
#include <stdint.h>

t_lstiter		*new_lstiter(t_lst *l, t_lst_direction d)
{
	t_lstiter	*new_it;

	if (!(new_it = malloc(sizeof(t_lstiter))))
		return (NULL);
	new_it->pos = d == increasing ? SIZE_MAX : lst_get_size(l);
	new_it->current = d == increasing ? lst_elem_back(l) : lst_elem_front(l);
	new_it->end = d == increasing ? lst_elem_front(l) : lst_elem_back(l);
	new_it->dir = d;
	new_it->flag = 0;
	return (new_it);
}
