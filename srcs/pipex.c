/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:37:18 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/02 16:09:32 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Redirige les fd d'entrée et de sortie transmis vers l'entrée / la sortie standard

void	redirection_in_out(int input, int output, t_structure *structure)
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
		redirection_in_out(structure->fd_in, structure->pipefd[1], structure);

	else if (structure->child = structure->nbr_commands - 1)
		redirection_in_out(structure->pipefd[2 * structure->child - 2], structure->fd_out, structure);

	else
		redirect_io(structure->pipefd[2 * structure->child - 2], structure->pipefd[2 * structure->child + 1], structure);

	close_fds();
}

int	main(int argc, char **argv, char **envp)
{
	t_structure	structure;
}
