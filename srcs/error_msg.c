/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:43 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:55 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	error_msg(char *cmd, char *issue, int err)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(issue, 2);
	ft_putstr_fd("\n", 2);
	return (err);
}

int	error_msg2(char *cmd, char *cmd2, char *issue, int err)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd2, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(issue, 2);
	ft_putstr_fd("\n", 2);
	return (err);
}
