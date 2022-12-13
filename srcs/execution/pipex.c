/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:45:04 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/13 15:48:54 by mkaploun         ###   ########.fr       */
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
	int			pipefd[2];
	int			i;
	int			nbr_commands;

	if (envp == NULL || envp[0][0] == '\0')
		error(msg("Unexpected error.", "", "", 1), &data);

	data = init_struct(commands, envp);
	/* printf("-----------------------------------------------------\n\n"); */
	/* print_struct(&data); */

	nbr_commands = commands_get_size(commands);
	fd[0] = -1;
	fd[1] = -1;
	pipefd[0] = -2;
	pipefd[1] = -2;
	i = 0;

	while (i < nbr_commands)
	{
		cmd = commands_get_i(data.commands, i);

		fd[0] = get_in_table(cmd, &in_table, &file_name, pipefd);
		printf("pour %s: fd[0] = %d\n", command_get_name(cmd), fd[0]);

		if (fd[0] == -1)
			printf("bash: %s: No such file or directory\n", file_name);

		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}

		printf("%s created pipe between %d -> %d\n", command_get_name(cmd), pipefd[1], pipefd[0]);

		if (i == nbr_commands - 1)
			pipefd[1] = STDOUT_FILENO;

		fd[1] = get_out_table(cmd, &out_table, pipefd);
		printf("pour %s: fd[1] = %d\n", command_get_name(cmd), fd[1]);

		launch_child(data, cmd, fd);
		waitpid(-1, NULL, 0);
		printf("cmd %s exited normally \n", command_get_name(cmd));
		i++;
	}

	clean_table_in(in_table, cmd);
	clean_table_out(out_table, cmd);
	return (0);
}

void	print_struct(t_data *data)
{
	commands_print(data->commands);
}
