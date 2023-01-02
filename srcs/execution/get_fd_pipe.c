/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:49 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:58 by ellana           ###   ########.fr       */
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
