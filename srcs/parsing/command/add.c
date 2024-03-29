/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:49 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:04 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

char	*_new_str(char *str)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	str_cpy(str, tmp);
	return (tmp);
}

int	command_add_arg(t_command *command, char *str)
{
	char	*tmp;

	tmp = _new_str(str);
	if (!tmp)
		return (1);
	ft_lstadd_back(command->args, ft_lstnew((void *)tmp));
	return (0);
}

int	command_add_out(t_command *command, char *str)
{
	t_funnel	*funnel;

	funnel = (t_funnel *)malloc(sizeof(t_funnel));
	if (!funnel)
		return (1);
	funnel->filename = _new_str(str);
	if (!funnel->filename)
		return (1);
	funnel->type = Out;
	ft_lstadd_back(command->out, ft_lstnew(funnel));
	return (0);
}

int	command_add_out_a(t_command *command, char *str)
{
	t_funnel	*funnel;

	funnel = (t_funnel *)malloc(sizeof(t_funnel));
	if (!funnel)
		return (1);
	funnel->filename = _new_str(str);
	if (!funnel->filename)
		return (1);
	funnel->type = Outa;
	ft_lstadd_back(command->out, ft_lstnew(funnel));
	return (0);
}

int	command_add_in(t_command *command, char *str)
{
	t_funnel	*funnel;

	funnel = (t_funnel *)malloc(sizeof(t_funnel));
	if (!funnel)
		return (1);
	funnel->filename = _new_str(str);
	if (!funnel->filename)
		return (1);
	funnel->type = In;
	ft_lstadd_back(command->in, ft_lstnew(funnel));
	return (0);
}
