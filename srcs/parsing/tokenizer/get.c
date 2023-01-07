/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:53 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:12 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

char	tokenizer_get_last_char(t_tokenizer *tokenizer)
{
	if (tokenizer->cmd_i > 0)
	{
		return (*(tokenizer->cmd_ptr - 1));
	}
	return (0);
}

char	tokenizer_get_char(t_tokenizer *tokenizer)
{
	return (*(tokenizer->cmd_ptr));
}

char	tokenizer_get_next_char(t_tokenizer *tokenizer, int s)
{
	if (tokenizer->cmd_i + s > tokenizer->size)
		return (0);
	return ((tokenizer->cmd_ptr)[s]);
}

t_token	*tokenizer_get_last_token(t_tokenizer *tokenizer)
{
	t_list	*last;

	last = ft_lstlast(*tokenizer->tokens);
	if (!last)
		return (NULL);
	return (last->content);
}
