#include "ftlst.h"
#include <stdlib.h>

void					lst_destroy(t_lst **lst)
{
	void				*data;
	t_lst				*list;

	list = *lst;
	while ((data = lst_pop_back(list)))
		free(data);
	free(list);
	*lst = NULL;
}
