/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 04:40:48 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 04:41:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "ftlst.h"
# include <termios.h>
# define BS (buf[0] == 27 && buf[1] == 91 && buf[2] == 51)

typedef struct		s_el
{
	char			*word;
	int				current;
	int				selected;
	size_t			size;
}					t_el;

typedef struct		s_env
{
	t_lst			*lst;
	struct termios	term;
	size_t			l;
	size_t			c;
}					t_env;

void				print_list(t_env *e);
void				delete_element(void *data);
int					init_termcaps(void);
void				restore_termcaps(void);
int					exit_ftselect(int ret);
t_env				*get_env(void);
void				signal_handler(int sig);
int					ft_putrchar(int c);
int					update_list(t_env *e, const char *buf);
void				chose_mode(t_env *e, t_el *data);

#endif
