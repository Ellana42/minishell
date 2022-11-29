/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:13:54 by lsalin            #+#    #+#             */
/*   Updated: 2022/11/29 15:24:10 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/pipe/pipex.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	file;
	pid = fork();

	if (pid == -1)
		return (1);

	if (pid == 0) // processus fils
	{
		file = open("file.txt", O_CREAT | O_WRONLY, 0777);
		
	}
}
