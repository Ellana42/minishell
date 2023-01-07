/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:49 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:05 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	commands_dispose(t_commands *commands)
{
	ft_lstclear(commands, &_free_command);
}

void	commands_free(t_commands *commands)
{
	free(commands);
}

void	commands_destroy(t_commands *commands)
{
	commands_dispose(commands);
	commands_free(commands);
}
