/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:18 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:39 by ellana           ###   ########.fr       */
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
