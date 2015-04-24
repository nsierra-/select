#include "libft.h"
#include "ftlst.h"
#include "ft_select.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <term.h>

static void		load_lst(t_lst *l, int ac, char **av)
{
	int			i;
	t_el		*new_el;
	t_el		*first;

	i = 1;
	while (i < ac)
	{
		if (!(new_el = malloc(sizeof(t_el))))
			return ;
		new_el->word = ft_strdup(av[i]);
		new_el->current = 0;
		new_el->selected = 0;
		lst_push_back(l, new_el);
		++i;
	}
	first = lst_data_front(l);
	first->current = 1;
}

static t_env	*init_env(void)
{
	t_env		*e;

	if (!getenv("TERM"))
		return (NULL);
	e = get_env();
	if (!(e->lst = new_lst()))
		return (NULL);
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGWINCH, signal_handler);
	init_termcaps();
	return (e);
}

static void		print_result(t_lst *lst)
{
	t_lstiter	*it;

	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putrchar);
	tputs(tgetstr("cl", NULL), 1, ft_putrchar);
	tputs(tgetstr("ve", NULL), 1, ft_putrchar);
	tputs(tgetstr("te", NULL), 1, ft_putrchar);
	it = new_lstiter(lst, increasing);
	while (lst_iterator_next(it))
	{
		if (((t_el *)it->data)->selected)
		{
			ft_putstr_fd(((t_el *)it->data)->word, 1);
			ft_putstr_fd(" ", 1);
		}
	}
	free(it);
}

int				main(int ac, char **av)
{
	t_env		*e;
	char		buf[4];

	if (ac == 1 || !(e = init_env()))
		return (EXIT_FAILURE);
	load_lst(e->lst, ac, av);
	while (42)
	{
		ft_bzero(buf, 4);
		print_list(e);
		if (read(0, buf, 4) < 0)
			return (exit_ftselect(EXIT_FAILURE));
		if (!update_list(e, buf))
			break ;
	}
	print_result(e->lst);
	lst_destroy(&e->lst, delete_element);
	return (EXIT_SUCCESS);
}
