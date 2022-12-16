#include "../execution/execution.h"

// env : permet de lister les variables d'environnement
// À gérer sans options ni arguments

int env_builtin(char **args, char **envp) 
{
	int	i;
	i = 0;

	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
  return 0;
}
