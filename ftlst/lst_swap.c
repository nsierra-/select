/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 03:56:16 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 03:56:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

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
