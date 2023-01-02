/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:47 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:57 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execution_dispose(t_execution *execution)
{
	free_pipes(execution->pipes, execution->executables_size);
	executables_destroy(execution->executables);
	glob_set_pids(NULL);
	int_lstclear(execution->pids);
	free(execution->pids);
}

void	execution_free(t_execution *execution)
{
	free(execution);
}

void	execution_destroy(t_execution *execution)
{
	execution_dispose(execution);
	execution_free(execution);
}
