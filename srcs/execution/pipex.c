/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:45:04 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/12 22:43:11 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// Parse les arguments, initialise la structure et launch ./pipex
// Renvoie le code de sortie du dernier fils, considéré comme le code de sortie de Pipex

int	pipex_launch(t_commands *commands, char **envp)
{
	t_data		data;
	t_command	*cmd;
	char		*file_name;
	int			*in_table;
	int			*out_table;
	int			fd[2];

	if (envp == NULL || envp[0][0] == '\0')
		error(msg("Unexpected error.", "", "", 1), &data);

	data = init_struct(commands, envp);
	/* printf("-----------------------------------------------------\n\n"); */
	/* print_struct(&data); */

	cmd = commands_get_i(data.commands, 0);
	fd[0] = get_in_table(cmd, &in_table, &file_name);
	if (fd[0] == -1)
		printf("bash: %s: No such file or directory\n", file_name);

	fd[1] = get_out_table(cmd, &out_table);

	launch_child(data, cmd, fd);
	waitpid(-1, NULL, 0);
	clean_table_in(in_table, cmd);
	clean_table_out(out_table, cmd);
	return (0);
}

void	print_struct(t_data *data)
{
	commands_print(data->commands);
}

