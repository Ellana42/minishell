/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:12 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:28 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

extern t_glob	*g_glob;

void	glob_set_env(t_list **env)
{
	*(g_glob->env) = env;
}

void	glob_set_exit_status(int exit_status)
{
	g_glob->exit_status = exit_status;
}

void	glob_set_pids(t_intlist **pids)
{
	*g_glob->pids = pids;
}

void	glob_set_state(int state)
{
	g_glob->activated = state;
}
