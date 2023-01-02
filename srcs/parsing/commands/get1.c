/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:43 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:43 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	commands_get_size(t_commands *commands)
{
	if (!commands)
		return (-1);
	return (ft_lstsize(*commands));
}
