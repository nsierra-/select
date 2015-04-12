#include "libft.h"
#include "ftlst.h"
#include "ft_select.h"
#include <stdlib.h>

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

void			pl(void *data)
{
	t_el		*dt;

	dt = (t_el *)data;
	if (dt->current)
		ft_putstr("---> ");
	ft_putstr(dt->word);
	if (dt->selected)
		ft_putstr("\nSelected");
}

int				main(int ac, char **av)
{
	t_lst		*lst;

	if (!(lst = new_lst()) || ac == 1)
		return (EXIT_FAILURE);
	load_lst(lst, ac, av);
	lst_print(lst, pl, 0);
	lst_destroy(&lst);
	return (EXIT_SUCCESS);
}
