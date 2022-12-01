/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:35:10 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/01 21:28:55 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipes(t_structure *structure)
{
	int	i;
	i = 0;

	while (i < structure->nbr_commands - 1) // On boucle tant qu'on n'a pas atteint le nombre d'arguments entrés par l'user
	{
		if (pipe(structure->pipe + 2 * i) == -1) // Création d'une paire de fd (pipe) pour chaque fils
			return (-1); // remplacer par msg d'erreur
		i++;
	}
}

void	clean_init_structure(void)
{
	t_structure	structure;
	
	structure.argc = -1;
	structure.child = -1;
	structure.input = -1;
	structure.output = -1;
	structure.fd_in = -1;
	structure.fd_out = -1;
	structure.nbr_commands = -1;
	structure.argc = NULL;
	structure.envp = NULL;
	structure.pipefd = NULL;
	structure.cmd = NULL;
}

// Redirige les fd d'entrée et de sortie transmis vers l'entrée / la sortie standard

void	redirection_in_out(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		return (-1); // à remplacer par msg d'erreur

	if (dup2(output, STDOUT_FILENO) == -1)
		return(-1);
}

// Définis les inputs & outputs des processus fils en fonction de leur index
// Tous les fils sauf le premier lit depuis le pipefd[2 * index - 2]
// Tous les fils sauf le dernier écrivent sur le pipedfd[2 * index + 1]

void	child(t_structure *structure)
{
	if (structure->child == 0)
		redirection_in_out(structure->fd_in, structure->pipefd[1]);
}
