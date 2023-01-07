/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:47 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:54:03 by mkaploun         ###   ########.fr       */
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
