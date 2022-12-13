#include "execution.h"

// Parse les arguments, initialise la structure et launch ./pipex
// Renvoie le code de sortie du dernier fils, considéré comme le code de sortie de Pipex
int	init_pipes(int ***pipes, int commands_size)
{
	int	i;
	int	pipefd[2];

	(*pipes) = (int **)malloc(sizeof(int *) * (commands_size));
	if (!pipes)
		return (1);
	i = 0;
	while (i < commands_size - 1)
	{
		(*pipes)[i] = (int *)malloc(sizeof(int) * 2);
		if (!(*pipes)[i])
			return (1);
		pipe(pipefd);
		(*pipes)[i][0] = pipefd[0];
		(*pipes)[i][1] = pipefd[1];
		i++;
	}
	pipes[i] = NULL;
	return (0);
}

void	print_pipes(int **pipes, int commands_size)
{
	int	i;

	i = 0;
	printf("_____________\n");
	while (pipes[i])
	{
		printf("|     |     |\n");
		printf("|  %d  |  %d  |\n", pipes[i][0], pipes[i][1]);
		i++;
	}
	printf("_____________\n");
}

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
	int			commands_size;
	int			**pipes;

	if (envp == NULL || envp[0][0] == '\0')
		error(msg("Unexpected error.", "", "", 1), &data);

	data = init_struct(commands, envp);

	cmd = NULL;
	commands_size = commands_get_size(commands);
	/* if (init_pipes(&pipes, commands_size)) */
	/* 	return (1); // TODO deal with that */
	/* print_pipes(pipes, commands_size); */
	fd[0] = -1;
	fd[1] = -1;
	pipefd[0] = -2;
	pipefd[1] = -2;
	i = 0;

	while (i < commands_size)
	{
		cmd = commands_get_i(data.commands, i);

		fd[0] = get_in_table(cmd, &in_table, &file_name, pipefd);

		if (fd[0] == -1)
			printf("bash: %s: No such file or directory\n", file_name);

		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}

		if (i == commands_size - 1)
			pipefd[1] = STDOUT_FILENO;

		fd[1] = get_out_table(cmd, &out_table, pipefd);

		launch_child(data, cmd, fd);
		waitpid(-1, NULL, 0);
		clean_table_in(&in_table, cmd);
		clean_table_out(&out_table, cmd);
		i++;
	}

	return (0);
}

void	print_struct(t_data *data)
{
	commands_print(data->commands);
}
