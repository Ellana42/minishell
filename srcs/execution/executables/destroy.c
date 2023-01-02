/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:48 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:58 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executables.h"

void	executables_dispose(t_executables *executables)
{
	ft_lstclear(executables, (void *)executable_destroy);
}

void	executables_free(t_executables *executables)
{
	free(executables);
}

void	executables_destroy(t_executables *executables)
{
	executables_dispose(executables);
	executables_free(executables);
}
