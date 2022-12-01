/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:35:10 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/01 13:48:05 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	int	pipefd[3][2];
	int	pid1;
	int	i;

	i = 0;
	
	while (i < 3)
	{
		if (pipe(pipefd[i] < 0))
			return (1);
		i++;
	}
	
	pid1 = fork();

	if (pid1 < 0)
		return (-1);
	
	if (pid1 == 0) // child 1
	{
		
	}
}
