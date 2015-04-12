#include "ftlst.h"
#include <stdlib.h>

void					lst_del(t_lst *lst, size_t pos)
{
	void				*data;

	if ((data = lst_remove(lst, pos)))
		free(data);
}
