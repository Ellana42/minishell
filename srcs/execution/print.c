/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:47 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:57 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execution_print(t_execution *execution)
{
	printf("Executables : \n");
	executables_print(execution->executables);
	printf("Pipes : \n");
	print_pipes(execution->pipes);
	printf("Executable size : %d\n", (int )execution->executables_size);
	printf("Pids : ");
	int_lstprint(*execution->pids);
	printf("\n");
}
