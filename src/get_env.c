#include "ft_select.h"

t_env				*get_env(void)
{
	static t_env	env;

	return (&env);
}