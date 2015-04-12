/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_insert_between.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 03:53:39 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 03:53:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

void	elem_insert_between(
			t_lstelem *to_insert,
			t_lstelem *before,
			t_lstelem *after)
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
