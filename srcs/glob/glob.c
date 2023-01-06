#include "glob.h"

extern t_glob	*g_glob;

void	glob_print(t_bool print_env)
{
	printf("Glob : \n");
	printf("Activated : %d\n", glob_get_state());
	printf("Exit status : %d\n", glob_get_exit_status());
	if (print_env)
		env_print();
}
