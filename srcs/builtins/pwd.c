#include "../builtins/builtin.h"

// pwd : affiche le chemin absolu du repertoire de travail actuel

// char *getcwd(char *buf, size_t size);
// Recupere le chemin du repertoire de travail courant
// - buf : pointeur sur tableau de chars, constitue du path
// - size : taille de buf

typedef struct s_data
{
	char	*working_directory;
	char	**env;
}	t_data;

int	pwd(t_data *data, char **args)
{
	char	*buf[PATH_MAX];
	char	*cwd;

	(void)args;

	if (data->working_directory)
	{
		ft_putendl_fd(data->working_directory, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}

	cwd = getcwd(buf, PATH_MAX);

	if (cwd)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}

	// TODO message d'erreur fail pwd avec strerror(erno) par exemple
	return (EXIT_FAILURE);
}

// PLUS SIMPLE :

// void	pwd(void) 
// {
// 	char cwd[PATH_MAX];

// 	if (getcwd(cwd, sizeof(cwd))
// 		printf("%s\n", cwd);
// 	perror("getcwd() error");
// }
