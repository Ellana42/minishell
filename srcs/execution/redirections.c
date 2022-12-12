/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:42:23 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/12 14:38:24 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int get_in_table(t_command *cmd, int **in_table, char **file_name)
{
	t_funnel		*funnel;
	int 			size;
	int 			last_fd;
	int 			i;
	int				err;
	int				fd;
	t_token_type	type;

	i = 0;
	err = 0;

	size = ft_lstsize(*command_get_in(cmd));
	*in_table = (int *)malloc(sizeof(int) * size);
	if (size == 0)
		return (-2);

	last_fd = -1;

	while (i < size)
	{
		funnel = lst_get_i(*command_get_in(cmd), i);
		*file_name = funnel_get_filename(funnel);
		type = funnel_get_type(funnel);
		fd = open(*file_name, O_RDONLY, 0644);

		if (fd == -1)
			err = 1;

		(*in_table)[i] = fd;
		if ((*in_table)[i] == -1)
			printf("Error !\n"); // TODO gérer erreur
		last_fd = (*in_table)[i];
		i++;
	}
	if (err)
		return (-1);
	return (last_fd);
}

int get_out_table(t_command *cmd, int **out_table)
{
	t_funnel		*funnel;
	int 			size;
	int 			last_fd;
	int 			i;
	t_token_type	type;
	char 			*file_name;

	i = 0;

	size = ft_lstsize(*command_get_out(cmd));
	*out_table = (int *)malloc(sizeof(int) * size);

	last_fd = -1;

	while (i < size)
	{
		funnel = lst_get_i(*command_get_out(cmd), i);
		file_name = funnel_get_filename(funnel);
		type = funnel_get_type(funnel);
		(*out_table)[i] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if ((*out_table)[i] == -1)
			printf("Error !\n"); // TODO gérer erreur
		last_fd = (*out_table)[i];
		i++;
	}
	return (last_fd);
}

int clean_table_out(int *out_table, t_command *cmd)
{
	int size;
	int i;

	size = ft_lstsize(*command_get_out(cmd));
	i = 0;

	while (i < size)
	{
		if (out_table[i] >= 0)
			close(out_table[i]);
		i++;
	}
	free(out_table);
	return (0);
}

int clean_table_in(int *in_table, t_command *cmd)
{
	int size;
	int i;

	size = ft_lstsize(*command_get_in(cmd));
	i = 0;

	while (i < size)
	{
		if (in_table[i] >= 0)
			close(in_table[i]);
		i++;
	}
	free(in_table);
	return (0);
}
