#include "env.h"

// env : permet de lister les variables d'environnement
// À gérer sans options ni arguments
int	env(char **args)
{
	if (table_get_size(args) > 1)
	{
		error_msg("env", "too many arguments", 0);
		return (1);
	}
	env_print();
	return (0);
}
