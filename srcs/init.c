/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:07:40 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/03 12:34:48 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Créer un pipe (cad une paire de fds) pour chaque commande

void	create_pipes(t_data *data)
{
	int	i;
	i = 0;

	while (i < data->nbr_commands - 1) // On boucle tant qu'on n'a pas atteint le nombre d'arguments entrés par l'user
	{
		if (pipe(data->pipefd + 2 * i) == -1) // Création d'une paire de fd (pipe) pour chaque fils
			return (-1); // remplacer par msg d'erreur
		i++;
	}
}

// Initialisation "propre" de notre data
// On pourra call cette fonction avant d'utiliser les valeurs de notre data
// -1 pour les variables qui ne sont pas des strings car 0 est une valeur possible de fd

void	clean_init_data(void)
{
	t_data	data;
	
	data.argc = -1;
	data.argv = NULL;
	data.envp = NULL;
	data.path_ultime = NULL;
	data.array_of_paths = NULL;
	data.pipefd = NULL;
	data.nbr_commands = -1;
	data.input = -1;
	data.output = -1;
	data.fd_in = -1;
	data.fd_out = -1;
	data.child = -1;
	data.pids = NULL;
	data.cmd = NULL;
	data.heredoc = 0;

	return (data);
}

t_data	init_data(int argc, char **argv, char **envp)
{
	t_data	data;
	data = clean_init_data;

	data.argc = argc;
	data.argv = argv;
	data.envp = envp;

	if (ft_strncmp("here_doc", argv[1], 9) == 0) // Si here_doc == argv[1]
		data.heredoc = 1;
	get_input_file(&data);
	get_output_file(&data);

	data.nbr_commands = argc - 3 - data.heredoc;
	data.pids = malloc(sizeof * data.pipe * 2 * (data.nbr_commands - 1));

	if (!data.pipe)
		error(msg("Pipe error", "", "", 1), &data);

	create_pipes(&data);

	return (data);
}
