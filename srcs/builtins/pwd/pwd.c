/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:44 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:56 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

// pwd : affiche le chemin absolu du repertoire de travail actuel

// char *getcwd(char *buf, size_t size);
// Recupere le chemin du repertoire de travail courant
// - buf : pointeur sur tableau de chars, constitue du path
// - size : taille de buf

int	pwd_builtin(char **args)
{
	char	*buf;
	char	*cwd;

	(void)args;
	buf = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	cwd = getcwd(buf, PATH_MAX);
	if (cwd)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		free(buf);
		return (EXIT_SUCCESS);
	}
	free(buf);
	if (glob_env_has_var("PWD"))
		printf("%s\n", glob_getenv_var("PWD"));
	return (EXIT_FAILURE);
}

// PLUS SIMPLE :

// void	pwd(void) 
// {
// 	char cwd[PATH_MAX];

// 	if (getcwd(cwd, sizeof(cwd))
// 		printf("%s\n", cwd);
// 	perror("getcwd() error");
// }
