/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:49 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:58 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execution_get_pid(t_execution *execution)
{
	if (!(*execution->pids))
		return (-1);
	return ((*execution->pids)->content);
}

int	execution_is_command(t_execution *execution)
{
	if (command_get_name(execution_get_current_command(execution)))
		return (1);
	return (0);
}
