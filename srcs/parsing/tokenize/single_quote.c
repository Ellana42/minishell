/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:13:58 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:14:41 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	tokenize_single_quote(t_tokenizer *tokenizer)
{
	tokenizer_set_not_empty_acc(tokenizer);
	if (tokenizer_get_char(tokenizer) == '\'')
	{
		tokenizer->state = NoQuote;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	tokenizer_accumulate(tokenizer);
	return (0);
}
