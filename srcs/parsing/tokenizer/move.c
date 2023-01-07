/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:55:59 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:12 by mkaploun         ###   ########.fr       */
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
