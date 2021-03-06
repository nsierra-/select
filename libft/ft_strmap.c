/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:57:43 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 14:38:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*str_new;

	i = 0;
	str_new = malloc(sizeof(str_new) * ft_strlen((char *)s) + 1);
	if (str_new)
	{
		ft_strcpy(str_new, s);
		while (s[i])
		{
			str_new[i] = (*f)(s[i]);
			i++;
		}
		return (str_new);
	}
	else
		return (NULL);
}
