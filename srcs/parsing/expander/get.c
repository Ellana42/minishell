/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:51 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:06 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	expander_get_last_char(t_expander *expander)
{
	if (expander->cmd_i > 0)
	{
		return (*(expander->cmd_ptr - 1));
	}
	return (0);
}

char	expander_get_char(t_expander *expander)
{
	return (*(expander->cmd_ptr));
}

char	expander_get_next_char(t_expander *expander, int s)
{
	if (expander->cmd_i + s > expander->size)
		return (0);
	return ((expander->cmd_ptr)[s]);
}
