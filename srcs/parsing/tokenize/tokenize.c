/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:53 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	tokenize(t_tokenizer *tokenizer)
{
	if (tokenizer->state == NoQuote)
		return (tokenize_noquote(tokenizer));
	if (tokenizer->state == Quote)
		return (tokenize_quote(tokenizer));
	if (tokenizer->state == SingleQuote)
		return (tokenize_single_quote(tokenizer));
	return (0);
}
