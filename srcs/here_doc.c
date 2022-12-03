/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:40:28 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/03 12:40:06 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Définis le fd du input file
// Un fichier temporaire est créée si un heredoc est spécifié
// Si ce n'est pas le cas, l'input file spécifié sera ouvert.

void	get_input_file(t_data *data)
{
	if (data->heredoc == 1) // si heredoc spécifié
	{
		get_heredoc(data);
		data->fd_in = open(".heredoc.tmp", O_RDONLY);

		if (data->fd_in == -1)
			return (-1); // à remplacer par msg d'erreur avec strerror ...
	}

	else
		data->fd_in = open(data->argv[1], O_RDONLY, 644);
		if (data->fd_in == -1)
			return (-1); // à remplacer par msg d'erreur avec strerror ...
}

// Ouvre/créée un output file
// Si un heredoc est spécifié, le output file sera ajouté 
// Sinon il sera écrasé

void	get_output_file(t_data *data)
{
	if (data->heredoc == 1)
		data->fd_out = open(data->argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);

	else
		data->fd_out = open(data->argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	if (data->fd_out == -1)
		return (-1); // à remplacer par msg d'erreur avec strerror ...
}

// Lit à partir de la stdin et stocke les lignes lues dans un fichier temporaire
// jusqu'à que le DELIMITEUR soit rencontré
// Définis ensuite le fd du input file de pipex comme ce fichier temporaire

void	get_heredoc(t_data *data)
{
	int		tmp_fd;
	int		stdin_fd;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO); // stdin_fd = copie du fd stdin

	if (tmp_fd == -1)
		return (-1); // À remplacer par msg d'erreur avec strerror ...

	line = "";

	while (1) // on boucle indéfiniment pour lire chaque ligne de la stdin
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(stdin_fd);

		if (line == NULL)
			break ;

		if	((ft_strlen(data->argv[2]) + 1 == ft_strlen(line)) && 
			(ft_strncmp(line, data->argv[2], ft_strlen(data->argv[2]) + 1) == 0))
		// Si la ligne == DELIMITEUR on close le fd stdin
			close(stdin_fd);

		else // sinon on l'écrit dans le fd de notre fichier tempo
			ft_putstr_fd(line, tmp_fd);

		free(line);
	}
	close(tmp_fd);
}
