/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:37 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:43 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execution_dispose(t_execution *execution)
{
	free_pipes(execution->pipes, execution->executables_size);
	executables_destroy(execution->executables);
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
