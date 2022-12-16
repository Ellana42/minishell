#include "executables.h"

t_executable	*executables_get_i(t_executables *executables, int index)
{
	return ((t_executable *)ft_lstget_i(*executables, index));
}
