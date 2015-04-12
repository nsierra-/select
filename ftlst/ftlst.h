/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 04:25:01 by nsierra-          #+#    #+#             */
/*   Updated: 2015/04/12 04:25:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLST_H
# define FTLST_H
# include <stddef.h>

typedef struct			s_lstelem
{
	void				*data;
	struct s_lstelem	*prev;
	struct s_lstelem	*next;
}						t_lstelem;

typedef struct			s_lst
{
	size_t				size;
	t_lstelem			*first;
}						t_lst;

t_lstelem				*new_lstelem(void *data);
void					elem_insert_between(
							t_lstelem *to_insert,
							t_lstelem *before,
							t_lstelem *after);
void					elem_swap(t_lstelem *elem1, t_lstelem *elem2);
void					*elem_destroy(t_lstelem **elem);
t_lst					*new_lst(void);
size_t					lst_get_size(t_lst *lst);
int						lst_is_empty(t_lst *lst);
t_lstelem				*lst_elem_at(t_lst *lst, size_t pos);
void					*lst_data_at(t_lst *lst, size_t pos);
t_lstelem				*lst_elem_front(t_lst *lst);
t_lstelem				*lst_elem_back(t_lst *lst);
void					*lst_data_front(t_lst *lst);
void					*lst_data_back(t_lst *lst);
int						lst_push_back(t_lst *lst, void *data);
int						lst_push_front(t_lst *lst, void *data);
void					*lst_pop_back(t_lst *lst);
void					*lst_pop_front(t_lst *lst);
int						lst_insert(t_lst *lst, void *data, size_t pos);
void					*lst_remove(t_lst *lst, size_t pos);
void					lst_del(t_lst *lst, size_t pos);
void					lst_swap(t_lst *lst, size_t pos1, size_t pos2);
void					lst_bubble_sort(t_lst *lst, int (*f)(void *, void *));
void					lst_print(t_lst *lst, void (*print_f)(void *), int m);
void					lst_clear(t_lst *lst);
void					lst_destroy(t_lst **lst);

#endif
