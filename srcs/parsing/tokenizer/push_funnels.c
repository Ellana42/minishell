/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funnels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:55:59 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:12 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	tokenizer_push_out(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (!token)
		return (1);
	if (token_init_out(token, tokenizer->cmd_i, tokenizer_get_char(tokenizer)))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_outa(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (!token)
		return (1);
	if (token_init_outa(token, tokenizer->cmd_i, tokenizer_get_char(tokenizer)))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_in(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (!token)
		return (1);
	if (token_init_in(token, tokenizer->cmd_i, tokenizer_get_char(tokenizer)))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_ina(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (!token)
		return (1);
	if (token_init_ina(token, tokenizer->cmd_i, tokenizer_get_char(tokenizer)))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}
