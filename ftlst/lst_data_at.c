#include "ftlst.h"

void	*lst_data_at(t_lst *lst, size_t pos)
{
	return (lst_elem_at(lst, pos)->data);
}