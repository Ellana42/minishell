/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:41 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:42 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	command_print(t_command *command)
{
	printf("Command :\n");
	printf("- command : %s\n", command->command);
	printf("- args : ");
	print_str_chain(*command->args);
	printf("\n- out : ");
	print_funnel_chain(*command->out);
	printf("\n- in : ");
	print_funnel_chain(*command->in);
	printf("\n");
	printf("\n");
}
