#include "libft.h"
#include "ftlst.h"

typedef struct	s_test
{
	char		*foo;
	int			bar;
}				t_test;

int		cmp(void *data1, void *data2)
{
	return (ft_strcmp((char *)data1, (char *)data2));
}

int			main(void)
{
	t_lst	*lst;
	t_test	t;
	char	*foo = "lolilol";
	char	*bar = "MDR";

	t.foo = foo;
	t.bar = 4;
	lst = new_lst();
	lst_push_back(lst, foo);
	lst_push_back(lst, bar);
	lst_bubble_sort(lst, cmp);
	ft_putendl(lst_data_front(lst));
	ft_putendl(lst_data_back(lst));
	return (0);
}
