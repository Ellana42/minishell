#include "env.h"

// env : permet de lister les variables d'environnement
// À gérer sans options ni arguments
int	env(char **args)
{
	int		i;
	char	**env;

	i = 0;
	if (table_get_size(args) > 1)
	{
		printf("minishell: env: too many arguments\n");
		return (1);
	}
	env_print();
	return (0);
}
