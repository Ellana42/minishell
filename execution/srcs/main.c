/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:37:18 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/05 14:57:38 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Redirige les fd d'entrée et de sortie transmis vers la stdin et la stdout

static void	redirection_in_out(int input, int output, t_data *data)
{
	if (dup2(input, STDIN_FILENO) == -1)
		error(1, data);

	if (dup2(output, STDOUT_FILENO) == -1)
		error(1, data);
}

// Définis les inputs & outputs des processus fils en fonction de leur index
// Tous les fils sauf le premier lit depuis le pipefd[2 * index - 2]
// Tous les fils sauf le dernier écrivent sur le pipedfd[2 * index + 1]
// Puis execute la commande requise

static void	child(t_data *data)
{
	if (data->child == 0) // premier fils (index 0)
		redirection_in_out(data->fd_in, data->pipefd[1], data);

	else if (data->child = data->nbr_commands - 1)
		redirection_in_out(data->pipefd[2 * data->child - 2], data->fd_out, data);

	else
		redirection_in_out(data->pipefd[2 * data->child - 2], data->pipefd[2 * data->child + 1], data);

	close_fds(data);

	if (data->array_of_paths == NULL || data->path_ultime == NULL)
		error(1, data);

	if (execve(data->path_ultime, data->array_of_paths, data->envp) == -1)
		error(msg(data->array_of_paths[0], ": ", strerror(errno), 1), data);
}

// Attends que les processus fils se terminent et récupère le statut du dernier fils
// Renvoie le code d'état de sortie du dernier fils

static int	parent(t_data *data)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	close_fds(data);

	data->child--;

	exit_code = 1;

	while (data->child >= 0)
	{
		wpid = waitpid(data->pids[data->child], &status, 0);
		// wpid = pid du child qui s'est terminé
		if (wpid == data->pids[data->nbr_commands - 1])
		{
			if ((data->child == (data->nbr_commands - 1) && (WIFEXITED(status) != 0)))
				exit_code = WEXITSTATUS(status); // exit_code = code de sortie du fils
		}
		data->child--;
	}
	free(data->pipefd);
	free(data->pids);

	return (exit_code);
}

// Créer un pipe, fork et call la fonction parent() pour attendre que les processus
// fils finissent leurs tâches avant de se terminer
// Renvoie le code de sortie du dernier fils

static int	pipex(t_data *data)
{
	int	exit_code;

	if (pipe(data->pipefd) == -1)
		error(msg("pipe", ":", strerror(errno), 1), data);

	data->child = 0;

	while (data->child < data->nbr_commands)
	{
		data->array_of_paths = ft_split(data->argv[data->child + 2 + data->heredoc], ' ');

		if (data->array_of_paths == NULL)
			error(msg("unexpected error", "", "", 1), data);

		data->path_ultime = get_user_cmd(data);
		data->pids[data->child] = fork();

		if (data->pids[data->child] == -1)
			error(msg("fork", ": ", strerror(errno), 1), data);

		else if (data->pids[data->child] == 0)
			child(data);

		free_strs(data->path_ultime, data->array_of_paths);
		data->child++;
	}
	exit_code = parent(data);

	if (data->heredoc == 1)
		unlink(".heredoc.tmp");

	return (exit_code);
}

// Parse les arguments, initialise la structure et launch ./pipex
// Renvoie le code de sortie du dernier fils, considéré comme le code de sortie de Pipex

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		exit_code;
	
	if (argc < 5)
	{
		if (argc >= 2 && !ft_strncmp("here_doc", argv[1], 9))
			return (msg("Usage: ", "./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.", "", 1));
		return (msg("Usage: ", "./pipex file1 cmd1 cmd2 ... cmdn file2.", "", 1));
	}

	else if (argc < 6 && !ft_strncmp("here_doc", argv[1], 9))
		return (msg("Usage: ", "./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.", "", 1));

	if (envp == NULL || envp[0][0] == '\0')
		error(msg("Unexpected error.", "", "", 1), &data);

	data = init_struct(argc, argv, envp);

	exit_code = pipex(&data);
	return (exit_code);
}
