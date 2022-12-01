/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:35:10 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/01 20:55:14 by lsalin           ###   ########.fr       */
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
	structure.input = -1;
	structure.output = -1;
	structure.nbr_commands = -1;
	structure.argc = NULL;
	structure.envp = NULL;
	structure.pipe = NULL;
	structure.cmd = NULL;
}

// Redirige les fd d'entrée et de sortie transmis vers l'entrée / la sortie standard

void	redirection_in_out(t_structure *structure)
{
	if (dup2(structure->input, STDIN_FILENO) == -1)
		return (-1); // à remplacer par msg d'erreur

	if (dup2(structure->output, STDOUT_FILENO) == -1)
		return(-1);
}
