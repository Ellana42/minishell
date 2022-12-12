/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:05:52 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/12 15:30:05 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	get_here_doc(char *delimiter)
{
	int		tmp_fd;
	int		len_delimiter;
	char	*line;
	int		flag;

	if (!delimiter)
		return (-2);

	len_delimiter = ft_strlen(delimiter);
	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	if (tmp_fd < 0)
		return (tmp_fd);

	line = "";

	flag = 1;

	while (flag)
	{
		line = readline("> ");

		if (line == NULL)
			break ;
		
		if (!ft_strncmp(line, delimiter, len_delimiter + 1))
			flag = 0;

		else
		{
			ft_putstr_fd(line, tmp_fd); // sinon on stocke la ligne dans le fichier tempo
			ft_putstr_fd("\n", tmp_fd);
		}
		free(line);
	}
	return (tmp_fd);
}
