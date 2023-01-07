/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:55:59 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:12 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_token	*tokenizer_get_token(t_tokenizer *tokenizer, int i)
{
	int		j;
	t_list	*current_token;

	j = 0;
	if (!tokenizer->tokens)
		return (NULL);
	current_token = *(tokenizer->tokens);
	while (j < i)
	{
		if (!current_token)
			return (NULL);
		current_token = current_token->next;
		j++;
	}
	if (current_token)
		return ((t_token *)current_token->content);
	return (NULL);
}
