/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:42:23 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/11 12:46:34 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	get_out_table(t_command *cmd, int **out_table)
{
	int		outsize;
	int		last_fd;
	int		i;
	char	*file_name;

	i = 0;

	outsize = ft_lstsize(*command_get_out(cmd));
	*out_table = (int *)malloc(sizeof(int) * outsize);

	last_fd = -1;

	while (i < outsize)
	{
		file_name = lst_get_i(*command_get_out(cmd), i);
		(*out_table)[i] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if ((*out_table)[i] == -1)
			printf("Error !\n"); // TODO gérer erreur
		last_fd = (*out_table)[i];
		i++;
	}
	return (last_fd);
}

int	clean_table(int *out_table)
{
	
	return (0);
}
