#include "executables.h"

void	executables_print(t_executables *executables)
{
	ft_lstiter(*executables, &executable_print);
}
