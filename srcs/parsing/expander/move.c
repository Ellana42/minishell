/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:16:32 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:16:33 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	expander_move_cursor_two(t_expander *expander)
{
	expander_move_cursor(expander);
	expander_move_cursor(expander);
	return (0);
}

int	expander_move_cursor(t_expander *expander)
{
	(expander->cmd_ptr)++;
	(expander->cmd_i)++;
	return (0);
}

int	expander_move_accumulator(t_expander *expander)
{
	acc_move(expander->acc);
	return (0);
}
