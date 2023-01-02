/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:46 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:56 by ellana           ###   ########.fr       */
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
