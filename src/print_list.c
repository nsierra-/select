#include "ft_select.h"
#include "libft.h"
#include <term.h>
#include <stdlib.h>
#include <unistd.h>

static void		init_printing(t_vector *cur)
{
	cur->x = 0;
	cur->y = 0;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putrchar);
	tputs(tgetstr("cd", NULL), 1, ft_putrchar);
}

static void		print_word(t_env *e, t_el *data, t_vector *cur)
{
	(void)e;
	tputs(tgetstr("us", NULL), 1, ft_putrchar);
    ft_putstr_fd(data->word, isatty(STDOUT_FILENO));
    tputs(tgetstr("ue", NULL), 1, ft_putrchar);
	// ft_putstr_fd(data->word, e->term_fd);
	++cur->y;
	tputs(tgoto(tgetstr("cm", NULL), cur->x, cur->y), 1, ft_putrchar);
}

void			print_list(t_env *e)
{
	t_vector	cur;
	t_lstiter	*it;

	init_printing(&cur);
	it = new_lstiter(e->lst, increasing);
	while (lst_iterator_next(it))
		print_word(e, (t_el *)it->data, &cur);
	free(it);
}