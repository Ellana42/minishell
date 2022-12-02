/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:09:10 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/02 16:09:27 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_print_putstr(void)
{
	ft_putstr_fd("\033[31mError: bad arguments\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
}

void	free_strs(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}

// Ferme les extremites lecture & ecriture des 2 fds de chaque pipe

void	close_pipe_fds(t_structure *structure)
{
	int	i;
	i = 0;

	while ((i < structure->nbr_commands - 1) * 2)
	(
		close(structure->pipefd[i])
		i++;
	)
}

// Ferme tous les fd ouverts

void	close_fds(t_structure *structure)
{
	if (structure->fd_in != -1)
		close(structure->fd_in);

	if (structure->fd_in != -1)
		close(structure->fd_out);

	close_pipe_fds(structure);
}
