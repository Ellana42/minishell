/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:37:18 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/03 12:39:12 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Redirige les fd d'entrée et de sortie transmis vers l'entrée / la sortie standard

void	redirection_in_out(int input, int output, t_data *data)
{
	if (dup2(input, STDIN_FILENO) == -1)
		return (-1); // à remplacer par msg d'erreur

	if (dup2(output, STDOUT_FILENO) == -1)
		return(-1);
}

// Définis les inputs & outputs des processus fils en fonction de leur index
// Tous les fils sauf le premier lit depuis le pipefd[2 * index - 2]
// Tous les fils sauf le dernier écrivent sur le pipedfd[2 * index + 1]
// Puis execute la commande requise

void	child(t_data *data)
{
	if (data->child == 0)
		redirection_in_out(data->fd_in, data->pipefd[1], data);

	else if (data->child = data->nbr_commands - 1)
		redirection_in_out(data->pipefd[2 * data->child - 2], data->fd_out, data);

	else
		redirect_io(data->pipefd[2 * data->child - 2], data->pipefd[2 * data->child + 1], data);

	close_fds(data);

	if (data->array_of_paths == NULL || data->path_ultime == NULL)
		error(1, data);

	if (execve(data->path_ultime, data->array_of_paths, data->envp) == -1)
		error(msg(data->array_of_paths[0], ": ", strerror(errno), 1), data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
}
