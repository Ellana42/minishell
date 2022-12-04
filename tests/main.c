/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:09:00 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/04 21:09:11 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	// Vérifiez que les arguments sont valides
	if (argc < 4) {
		fprintf(stderr, "Usage: %s <cmd1> <cmd2> <arg1> [<arg2>...]\n", argv[0]);
		return 1;
	}

	int pipefd[2];

	// Créez un pipe
	if (pipe(pipefd) == -1) {
		perror("pipe");
		return 1;
	}

	// Créez un processus enfant
	if (fork() == 0) {
		// Dans le processus enfant, fermez l'extrémité en écriture du pipe
		close(pipefd[1]);

		// Redirigez l'entrée standard vers l'extrémité en lecture du pipe
		if (dup2(pipefd[0], STDIN_FILENO) == -1) {
			perror("dup2");
			return 1;
		}

		// Exécutez la deuxième commande en utilisant l'entrée standard redirigée
		execvp(argv[2], argv + 2);
	} else {
		// Dans le processus parent, fermez l'extrémité en lecture du pipe
		close(pipefd[0]);

		// Redirigez la sortie standard vers l'extrémité en écriture du pipe
		if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
			perror("dup2");
			return 1;
		}

		// Exécutez la première commande en utilisant la sortie standard redirigée
		execvp(argv[1], argv + 1);
	}

	// Attendez la fin des processus enfants
	wait(NULL);

	return 0;
}
