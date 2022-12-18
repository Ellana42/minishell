#include "execution.h"

// Ferme les extremites lecture & ecriture des 2 fds de chaque pipe

/*static void	close_pipe_fds(t_data *data)
{
	int	i;
	i = 0;
	while (i < (data->nbr_commands - 1) * 2)
	{
		close(data->pipefd[i]);
		i++;
	}
}*/

// En cas d'erreur, free & ferme les fds ouverts
// Détruit le fichier temporaire du heredoc puis termine le programme

void	error(int error_status)
{
	// if (data)
	// {
	// 	close_fds(data);

	// 	if (data->pipefd != NULL)
	// 		free(data->pipefd);

	// 	if (data->pids != NULL)
	// 		free(data->pids);

	// 	if (data->array_of_paths != NULL || data->cmd_path != NULL)
	// 		free_strs(data->cmd_path, data->array_of_paths);
	// }
	// if (data->heredoc == 1)
	// 	unlink(".heredoc.tmp");
	exit(error_status);
}

// Écrit un message d'erreur sur la sortie d'erreur
// Et retourne le code d'erreur

int	msg(char *str1, char *str2, char *str3, int erno)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);

	return (erno);
}

// Ferme tous les fd ouverts

/*void	close_fds(t_data *data)
{
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	close_pipe_fds(data);
}*/

void	free_strs(char *str, char **array_of_strs)
{
	int	i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	
	if (array_of_strs != NULL)
	{
		i = 0;
		while (array_of_strs[i])
		{
			free(array_of_strs[i]);
			i++;
		}
		free(array_of_strs);
		array_of_strs = NULL;
	}
}
