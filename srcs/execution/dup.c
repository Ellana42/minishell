/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:14 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:30 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execution_dup_in(int fd_in)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		return (1);
	}
	return (0);
}

int	execution_dup_out(int fd_out)
{
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		return (1);
	}
	return (0);
}
