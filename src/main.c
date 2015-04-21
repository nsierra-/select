#include "libft.h"
#include "ftlst.h"
#include "ft_select.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
	e->term_fd = -1;
	if (!(e->lst = new_lst()))
		return (NULL);
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	init_termcaps();
	return (e);
}

int				main(int ac, char **av)
{
	t_env		*e;
	char		buf[4];

	ft_bzero(buf, 4);
	if (ac == 1 || !init_env())
		return (EXIT_FAILURE);
	e = init_env();
	load_lst(e->lst, ac, av);
	while (42)
	{
		print_list(e);
		read(0, buf, 4);
	}
	return (exit_ftselect(EXIT_SUCCESS));
}
