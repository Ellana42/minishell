/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:47 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:54:03 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executable.h"

// TODO double check
void	executable_dispose(t_executable *executable)
{
	int	i;

	i = 0;
	while (i < executable->in_size)
	{
		free(executable->in_files[i]);
		i++;
	}
	free(executable->in_files);
	free(executable->out_files);
}

void	executable_free(t_executable *executable)
{
	free(executable);
}

void	executable_destroy(t_executable *executable)
{
	executable_dispose(executable);
	executable_free(executable);
}
