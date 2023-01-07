/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:47 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:54:03 by mkaploun         ###   ########.fr       */
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
