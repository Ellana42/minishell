/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:37 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:44 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	get_fd_in(int **pipes, int index_cmd)
{
	if (index_cmd == 0)
		return (STDIN_FILENO);
	return (pipes[index_cmd - 1][0]);
}

int	get_fd_out(int **pipes, int index_cmd, int commands_size)
{
	if (index_cmd == commands_size - 1)
		return (STDOUT_FILENO);
	return (pipes[index_cmd][1]);
}
