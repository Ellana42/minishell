/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:44 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:44 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_list	**commands_get_i_in(t_commands *commands, int i)
{
	t_command	*cmd;

	if (!commands)
		return (NULL);
	cmd = commands_get_i(commands, i);
	return (cmd->in);
}

t_list	**commands_get_i_ina(t_commands *commands, int i)
{
	t_command	*cmd;

	if (!commands)
		return (NULL);
	cmd = commands_get_i(commands, i);
	return (cmd->in_a);
}
