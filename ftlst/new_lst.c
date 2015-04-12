#include "ftlst.h"
#include <stdlib.h>

t_lst		*new_lst(void)
{
	t_lst	*new_list;

	if (!(new_list = malloc(sizeof(t_lst))))
		return (NULL);
	new_list->size = 0;
	new_list->first = NULL;
	return (new_list);
}
