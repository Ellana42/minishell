/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:37 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:43 by mkaploun         ###   ########.fr       */
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
