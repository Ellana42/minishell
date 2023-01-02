/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:46 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:46 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	commands_push(t_commands *commands, t_command *command)
{
	t_list	*new_command;

	new_command = ft_lstnew((void *)command);
	if (!new_command)
		return (1);
	ft_lstadd_back(commands, new_command);
	return (0);
}
