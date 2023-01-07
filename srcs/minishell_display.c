/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:51:55 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:00 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_struct.h"

void	minishell_env_el_print(void *content)
{
	t_dict	*dict;

	dict = (t_dict *)content;
	if (dict->value)
	{
		printf("%s=", dict->key);
		printf("%s\n", dict->value);
	}
}

void	minishell_env_print(t_minishell *minishell)
{
	ft_lstiter(**minishell->env, &minishell_env_el_print);
}

void	minishell_print(t_minishell *minishell, t_bool print_env)
{
	printf("Minishell : \n");
	if (print_env)
		minishell_env_print(minishell);
}
