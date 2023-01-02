/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:38 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:38 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

int	command_add_in_a(t_command *command, char *str)
{
	t_funnel	*funnel;

	funnel = (t_funnel *)malloc(sizeof(t_funnel));
	if (!funnel)
		return (1);
	funnel->filename = _new_str(str);
	if (!funnel->filename)
		return (1);
	funnel->type = Ina;
	ft_lstadd_back(command->in, ft_lstnew(funnel));
	return (0);
}
