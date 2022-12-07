/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:07:40 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/07 22:42:01 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// "Mise à nue" de notre structure
// On pourra call cette fonction avant d'utiliser les valeurs de notre structure
// -1 pour les variables qui ne sont pas des strings car 0 est une valeur possible de fd

static t_data	clean_init_struct(void)
{
	t_data	data;

	data.argc = -1;
	data.argv = NULL;
	data.envp = NULL;
	data.commands_options = NULL;
	data.cmd_path = NULL;
	data.nbr_commands = -1;
	data.pipefd = NULL;
	data.heredoc = 0;
	data.fd_in = -1;
	data.fd_out = -1;
	data.child = -1;
	data.pids = NULL;

	return (data);
}

// Créer un pipe (cad une paire de fds) pour chaque commande

static void	create_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_commands - 1) // On boucle tant qu'on n'a pas atteint le nombre d'arguments entrés par l'user
	{
		if (pipe(data->pipefd + 2 * i) == -1) // Création d'une paire de fd (pipe) pour chaque fils
			error(msg("Could not create pipe", "", "", 1), data);
		i++;
	}
}

// Initialise la structure en fonction des arguments fournis par l'user
// Créer les pipes pour chaque processus

t_data	init_struct(t_commands *commands, char **envp)
{
	t_data	data;
	data = clean_init_struct();

	data.envp = envp;
	/* data.argc = argc; */
	/* data.argv = argv; */

	data.commands = commands;
	if (ft_lstsize(*commands_get_i_ina(commands, 0)) > 0) // Si heredoc spécifié (argv[1])
		data.heredoc = 1;

	get_input_file(&data);
	get_output_file(&data);

	data.nbr_commands = commands_get_size(commands); // -3 car ./pipex infile outfile
	data.pids = malloc(sizeof * data.pids * data.nbr_commands);

	if (data.pids == 0)
		error(msg("PID error", strerror(errno), "", 1), &data);

	data.pipefd = malloc(sizeof * data.pipefd * 2 * (data.nbr_commands - 1));

	if (data.pipefd == 0)
		error(msg("Pipe error", "", "", 1), &data);

	create_pipes(&data);

	return (data);
}
