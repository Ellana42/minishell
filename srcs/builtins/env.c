#include "../execution/execution.h"

// env : permet de lister les variables d'environnement
// À gérer sans options ni arguments

int env_builtin(char **args, char **envp) 
{
	int	i;
	i = 0;

	if (args && args[1])
		return (-1); // TODO message d'erreur genre "too many arguments"

	if (!envp[i])
		return (EXIT_FAILURE);

	while (envp[i])
	{
		printf("%s\n", envp[i]); // ou ft_putendl_fd(envp[i++], STDOUT_FILENO);
		i++;
	}
  return 0;
}
