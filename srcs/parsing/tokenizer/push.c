/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:55:59 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:12 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	tokenizer_push_pipe(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (!token)
		return (1);
	if (token_init_pipe(token, tokenizer->cmd_i, tokenizer_get_char(tokenizer)))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_string(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;
	char	c;

	c = '\0';
	token = token_alloc();
	if (!token)
		return (1);
	c = tokenizer_get_last_char(tokenizer);
	if (token_init_str(token, tokenizer->acc->acc, tokenizer->cmd_i, c))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_eol(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (!token)
		return (1);
	if (token_init_eol(token, tokenizer->cmd_i, tokenizer_get_char(tokenizer)))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}
