#include "../builtins/env.h"

// env : permet de lister les variables d'environnement
// À gérer sans options ni arguments

int env_builtin(t_data *data, char **args) 
{
	int	i;
	i = 0;

	if (args && args[1])
		return (-1); // TODO message d'erreur genre "too many arguments"

	if (!data->env[i])
		return (EXIT_FAILURE);

	while (data->env[i])
	{
		printf("%s\n", data->env[i]); // ou ft_putendl_fd(envp[i++], STDOUT_FILENO);
		i++;
	}
  return 0;
}
