/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:07:40 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/02 16:30:17 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Créer un pipe (cad une paire de fds) pour chaque commande

void	create_pipes(t_structure *structure)
{
	int	i;
	i = 0;

	while (i < structure->nbr_commands - 1) // On boucle tant qu'on n'a pas atteint le nombre d'arguments entrés par l'user
	{
		if (pipe(structure->pipefd + 2 * i) == -1) // Création d'une paire de fd (pipe) pour chaque fils
			return (-1); // remplacer par msg d'erreur
		i++;
	}
}

// Initialisation "propre" de notre structure
// On pourra call cette fonction avant d'utiliser les valeurs de notre structure
// -1 pour les variables qui ne sont pas des strings car 0 est une valeur possible de fd

void	clean_init_structure(void)
{
	t_structure	structure;
	
	structure.argc = -1;
	structure.argv = NULL;
	structure.envp = NULL;
	structure.pipefd = NULL;
	structure.nbr_commands = -1;
	structure.input = -1;
	structure.output = -1;
	structure.fd_in = -1;
	structure.fd_out = -1;
	structure.child = -1;
	structure.cmd = NULL;

	return (structure);
}

t_structure	init_structure(int argc, char **argv, char **envp)
{
	t_structure	structure;
	structure = clean_init_structure;

	structure.argc = argc;
	structure.argv = argv;
	structure.envp = envp;

	if (!ft_strncmp())
}
