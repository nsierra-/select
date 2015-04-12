/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_elem_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 03:55:45 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 03:56:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

t_lstelem		*lst_elem_at(t_lst *lst, size_t pos)
{
	t_lstelem	*cursor;
	size_t		i;

	if (pos >= lst_get_size(lst))
		return (NULL);
	i = 0;
	cursor = lst_elem_front(lst);
	while (i++ < pos)
		cursor = cursor->next;
	return (cursor);
}
