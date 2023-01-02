/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acc_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:16 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:31 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	tokenizer_is_empty_acc_var(t_tokenizer *tokenizer)
{
	return (acc_is_empty(tokenizer->acc_var));
}

void	reset_acc_var(t_tokenizer *tokenizer)
{
	acc_reset(tokenizer->acc_var);
}

int	tokenizer_accumulate_var(t_tokenizer *tokenizer)
{
	acc_accumulate(tokenizer->acc_var, *(tokenizer->cmd_ptr));
	tokenizer_move_cursor(tokenizer);
	return (0);
}
