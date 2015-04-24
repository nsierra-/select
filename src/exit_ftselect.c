/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ftselect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 16:25:03 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/24 16:25:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				exit_ftselect(int ret)
{
	t_lst		*lst;

	lst = get_env()->lst;
	lst_destroy(&lst, delete_element);
	restore_termcaps();
	return (ret);
}
