/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:42:23 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/13 12:59:23 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int get_in_table(t_command *cmd, int **in_table, char **file_name, int pipefd[2])
{
	t_funnel		*funnel;
	int 			size;
	int 			last_fd;
	int 			i;
	int				err;
	t_token_type	type;

	*file_name = NULL;

	i = 1;
	err = 0;
	size = ft_lstsize(*command_get_in(cmd));
	*in_table = (int *)malloc(sizeof(int) * size);

	if (size == 0)
		return (-2);

	last_fd = pipefd[1];

	while (i < size)
	{
		funnel = lst_get_i(*command_get_in(cmd), i);
		*file_name = funnel_get_filename(funnel);
		type = funnel_get_type(funnel);

		if (type == In)
			(*in_table)[i] = open(*file_name, O_RDONLY, 0644); // TODO check si bonnes permissions

		if (type == Ina)
			(*in_table)[i] = get_here_doc(*file_name);

		if ((*in_table)[i] == -1)
			printf("Error !\n"); // TODO gérer erreur
		last_fd = (*in_table)[i];
		i++;
	}
	if (err)
		return (-1);
	return (last_fd);
}

int get_out_table(t_command *cmd, int **out_table, int pipefd[2])
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

	if (size == 0)
		return (-2);

	last_fd = pipefd[0];

	while (i < size)
	{
		funnel = lst_get_i(*command_get_out(cmd), i);
		file_name = funnel_get_filename(funnel);
		type = funnel_get_type(funnel);
		
		if (type == Out)
			(*out_table)[i] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644); // TODO check si bonnes permissions

		if (type == Outa)
			(*out_table)[i] = open(file_name, O_WRONLY| O_CREAT | O_APPEND, 0644);

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
	unlink(".heredoc.tmp"); // TODO deal with output
	free(in_table);
	return (0);
}
