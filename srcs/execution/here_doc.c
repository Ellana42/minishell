/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:40:28 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/07 11:33:59 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Définis le fd du input file
// Un fichier temporaire est créée si un heredoc est spécifié
// Si ce n'est pas le cas, l'input file spécifié sera ouvert

void	get_input_file(t_data *data)
{
	if (data->heredoc == 1) // si un heredoc est spécifié
	{
		get_heredoc(data);
		data->fd_in = open(".heredoc.tmp", O_RDONLY);

		if (data->fd_in == -1)
			error(msg("here_doc", ": ", strerror(errno), 1), data);
	}
	else
	{
		data->fd_in = open(data->argv[1], O_RDONLY, 644);

		if (data->fd_in == -1)
			msg(strerror(errno), ": ", data->argv[1], 1);
	}
}

// Ouvre/créée un output file
// Si un heredoc est spécifié, le output file sera ajouté 
// Sinon il sera écrasé

void	get_output_file(t_data *data)
{
	if (data->heredoc == 1)
		data->fd_out = open(data->argv[data->argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);

	else
		data->fd_out = open(data->argv[data->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (data->fd_out == -1)
		msg(strerror(errno), ": ", data->argv[data->argc - 1], 1);
}

// Ouvre un fichier temporaire et dupplique le fd de la stdin
// Lit les lignes entrées par l'user à partir de la stdin 
// et stocke les lignes lues dans le fichier temporaire
// jusqu'à que le LIMITER soit rencontré

void	get_heredoc(t_data *data)
{
	int		tmp_fd;
	int		stdin_fd;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO);

	if (tmp_fd == -1)
		error(msg("here_doc", ": ", strerror(errno), 1), data);

	line = "";

	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(stdin_fd);

		if (line == NULL)
			break ;
		// Si la taille du LIMITER == taille de la ligne ET que
		// ligne == LIMITER
		if (ft_strlen(data->argv[2]) + 1 == ft_strlen(line) && ft_strncmp(line, data->argv[2], ft_strlen(data->argv[2] + 1)) == 0)
			close(stdin_fd);
			
		else
			ft_putstr_fd(line, tmp_fd); // sinon on stocke la ligne dans le fichier tempo

		free(line);
	}
	close(tmp_fd);
}
