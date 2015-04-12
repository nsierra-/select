#include "ftlst.h"
#include <stdlib.h>

t_lstelem		*new_lstelem(void *data)
{
	t_lstelem	*new_elem;

	if (!(new_elem = malloc(sizeof(t_lstelem))))
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}
