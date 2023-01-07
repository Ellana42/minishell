/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:47 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:54:03 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executable.h"

void	print_pipe(int *pipe)
{
	if (!pipe)
		printf("None\n");
	else
		printf("%d <- %d\n", pipe[0], pipe[1]);
}

void	print_files(t_executable *executable)
{
	int	i;

	i = 0;
	printf("Size infiles : %d\n", (int )executable->in_size);
	printf("Infiles : ");
	while (i < executable->in_size)
	{
		if (executable->in_files[i][1] == -1)
			printf("%d - ", executable->in_files[i][0]);
		else
		{
			printf("(%d <-", executable->in_files[i][0]);
			printf(" %d) - ", executable->in_files[i][1]);
		}
		i++;
	}
	printf("\nSize outfiles : %d\n", (int )executable->out_size);
	i = 0;
	printf("Outfiles : ");
	while (i < executable->out_size)
	{
		printf("%d - ", executable->out_files[i]);
		i++;
	}
	printf("\n");
}

void	executable_print(void *executable_ptr)
{
	t_executable	*executable;

	printf("-----------------\n");
	executable = (t_executable *)executable_ptr;
	command_print(executable->command);
	printf("In pipe : ");
	print_pipe(executable->in_pipe);
	printf("Out pipe : ");
	print_pipe(executable->out_pipe);
	print_files(executable);
	printf("-----------------\n");
}
