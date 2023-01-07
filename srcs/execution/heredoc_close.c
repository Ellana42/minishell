/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:38 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:44 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	close_precedent_infiles(t_executable *executable, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		close_fd((executable->in_files)[i][0]);
		close_fd((executable->in_files)[i][1]);
		i++;
	}
}

// TODO close every fd for executables before current executable
int	close_everything(t_execution *execution, int index)
{
	int				i;
	t_executable	*executable;

	i = 0;
	while (i < execution->executables_size)
	{
		if (i < index)
		{
			executable = execution_get_executable_i(execution, i);
			if (executable_close_files(executable))
				return (1);
		}
		i++;
	}
	return (0);
}

void	close_pipes(t_execution *execution)
{
	int	i;

	i = 0;
	while (i < pipes_get_size(execution->pipes))
	{
		close_pipe(execution->pipes[i]);
		i++;
	}
}

void	eof_err(char *delimiter)
{
	ft_putstr_fd("warning: here-document delimited by end-of-file", 2);
	ft_putstr_fd(" (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
}

int	get_here_doc(char *delimiter, int fd[2], int len_delimiter, int exit)
{
	char	*line;
	char	*expanded_line;
	int		end;

	line = readline("> ");
	expanded_line = expand(line, exit);
	free(line);
	end = 0;
	if (!expanded_line)
	{
		eof_err(delimiter);
		end = 1;
	}
	else if (!ft_strncmp(expanded_line, delimiter, len_delimiter + 1))
		end = 1;
	else
	{
		ft_putstr_fd(expanded_line, fd[1]);
		ft_putstr_fd("\n", fd[1]);
	}
	free(expanded_line);
	return (end);
}
