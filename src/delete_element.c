#include <stdlib.h>
#include "ft_select.h"

void				delete_element(void *data)
{
	t_el			*el;

	el = (t_el *)data;
	free(el->word);
}