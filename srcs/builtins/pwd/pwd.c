#include "pwd.h"

// pwd : affiche le chemin absolu du repertoire de travail actuel

// char *getcwd(char *buf, size_t size);
// Recupere le chemin du repertoire de travail courant
// - buf : pointeur sur tableau de chars, constitue du path
// - size : taille de buf

int	pwd_builtin(char **args)
{
	char	*buf[PATH_MAX];
	char	*cwd;

	(void)args;
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
