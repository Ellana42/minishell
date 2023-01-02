/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:46 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:57 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executable.h"

char	*executable_get_name(t_executable *exe)
{
	if (!exe)
		return (NULL);
	return (command_get_name(exe->command));
}

int	**executable_get_in_files(t_executable *exe)
{
	if (!exe)
		return (NULL);
	return (exe->in_files);
}

int	*executable_get_out_files(t_executable *exe)
{
	if (!exe)
		return (NULL);
	return (exe->out_files);
}
