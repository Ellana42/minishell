/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:51:55 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:00 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	**minishell_get_env(t_minishell *minishell)
{
	return (*(minishell->env));
}

struct termios	*minishell_get_terminal(t_minishell *minishell, int term_index)
{
	if (term_index > 3)
		return (NULL);
	return (&minishell->terminal[term_index]);
}
