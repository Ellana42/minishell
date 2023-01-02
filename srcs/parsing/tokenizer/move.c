/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:17 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:38 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	tokenizer_move_cursor_two(t_tokenizer *tokenizer)
{
	tokenizer_move_cursor(tokenizer);
	tokenizer_move_cursor(tokenizer);
	return (0);
}

int	tokenizer_move_cursor(t_tokenizer *tokenizer)
{
	(tokenizer->cmd_ptr)++;
	(tokenizer->cmd_i)++;
	return (0);
}

int	tokenizer_move_accumulator(t_tokenizer *tokenizer)
{
	acc_move(tokenizer->acc);
	return (0);
}
