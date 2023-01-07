/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acc_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:50 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:06 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	expander_is_empty_acc_var(t_expander *expander)
{
	return (acc_is_empty(expander->acc_var));
}

void	expander_reset_acc_var(t_expander *expander)
{
	acc_reset(expander->acc_var);
}

int	expander_accumulate_var(t_expander *expander)
{
	acc_accumulate(expander->acc_var, *(expander->cmd_ptr));
	expander_move_cursor(expander);
	return (0);
}
