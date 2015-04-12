#include "ftlst.h"

void					lst_clear(t_lst *lst)
{
	while (lst_pop_back(lst))
		;
}
