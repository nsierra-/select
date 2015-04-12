/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 03:56:09 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 03:56:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"
#include "libft.h"

void					lst_print(t_lst *lst, void (*print_f)(void *), int mode)
{
	t_lstelem			*cursor;
	size_t				i;
	size_t				lsize;

	cursor = lst_elem_front(lst);
	i = 0;
	lsize = lst_get_size(lst);
	while (i++ < lsize)
	{
		ft_putendl("----------");
		if (mode == 1)
		{
			ft_putstr("Position : ");
			ft_putnbr((int)(i - 1));
			ft_putstr("\nData : ");
		}
		print_f(cursor->data);
		ft_putendl("\n----------");
		cursor = cursor->next;
	}
	ft_putstr("Total size : ");
	ft_putnbr(lst_get_size(lst));
	ft_putendl("");
}
