/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:16:29 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:16:29 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_expander	*expander_alloc(void)
{
	t_expander	*expander;

	expander = (t_expander *)malloc(sizeof(t_expander));
	return (expander);
}

int	expander_init(t_expander *expander, char *cmd, int last_err)
{
	char	*cmd_cpy;

	expander->size = ft_strlen(cmd);
	cmd_cpy = (char *)malloc(sizeof(char) * (expander->size + 1));
	expander->acc = acc_alloc();
	expander->acc_var = acc_alloc();
	if (!cmd_cpy || !expander->acc || !expander->acc_var)
		return (1);
	ft_strlcpy(cmd_cpy, cmd, expander->size + 1);
	expander->command = cmd_cpy;
	expander->cmd_ptr = expander->command;
	expander->cmd_i = 0;
	if (acc_init(expander->acc, expander->size))
		return (1);
	if (acc_init(expander->acc_var, expander->size))
		return (1);
	expander->state = Normal;
	expander->last_err = last_err;
	return (0);
}

void	expander_dispose(t_expander *expander)
{
	free(expander->command);
	acc_destroy(expander->acc);
	acc_destroy(expander->acc_var);
}

void	expander_free(t_expander *expander)
{
	free(expander);
}

void	expander_destroy(t_expander *expander)
{
	expander_dispose(expander);
	expander_free(expander);
}
