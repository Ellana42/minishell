/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:09:10 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/04 15:43:32 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Ferme les extremites lecture & ecriture des 2 fds de chaque pipe

void	close_pipe_fds(t_data *data)
{
	int	i;
	i = 0;

	while ((i < data->nbr_commands - 1) * 2)
	{
		close(data->pipefd[i]);
		i++;
	}
}

// Ferme tous les fd ouverts

void	close_fds(t_data *data)
{
	if (data->fd_in != -1)
		close(data->fd_in);

	if (data->fd_out != -1)
		close(data->fd_out);

	close_pipe_fds(data);
}

// En cas d'erreur, free & ferme les fds ouverts
// Détruit le fichier temporaire du heredoc puis termine le programme

void	error(int error_status, t_data *data)
{
	if (data != NULL)
	{
		close_fds(data);

		if (data->pipefd != NULL)
			free(data->pipefd);

		if (data->pids != NULL)
			free(data->pids);

		if (data->array_of_paths != NULL || data->path_ultime != NULL)
			free_strs(data->path_ultime, data->array_of_paths);
	}

	if (data->heredoc == 1)
		unlink(".heredoc.tmp");

	exit(error_status);
}

// Écrit un message d'erreur sur la sortie d'erreur
// Et retourne le code d'erreur

int	msg(char *str1, char *str2, char *str3, int erno)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);

	return (erno);
}

void	free_strs(char *str, char **strs)
{
	int	i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (strs != NULL)
	{
		i = 0;
		while (strs[i] != '\0')
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		strs = NULL;
	}
}
