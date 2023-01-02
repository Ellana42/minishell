/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:16 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:32 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	_token_print(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	token_print(token);
}

void	tokenizer_print_tokens(t_tokenizer *tokenizer)
{
	ft_lstiter(*(tokenizer->tokens), &_token_print);
}
