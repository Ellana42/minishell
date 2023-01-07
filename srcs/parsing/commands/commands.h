/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:54:43 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:14 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "../command/command.h"

typedef t_list *	t_commands;

void		commands_destroy(t_commands *commands);
t_commands	*commands_alloc(void);
int			commands_init(t_commands *commands);
void		_free_command(void *command);
void		commands_dispose(t_commands *commands);
void		commands_free(t_commands *commands);
void		commands_destroy(t_commands *commands);
int			commands_push(t_commands *commands, t_command *command);
int			commands_get_size(t_commands *commands);
void		commands_print(t_commands *commands);
t_command	*commands_get_i(t_commands *commands, int i);
t_list		**commands_get_i_args(t_commands *commands, int i);
t_list		**commands_get_i_out(t_commands *commands, int i);
t_list		**commands_get_i_outa(t_commands *commands, int i);
t_list		**commands_get_i_in(t_commands *commands, int i);
t_list		**commands_get_i_ina(t_commands *commands, int i);
int			commands_get_size(t_commands *commands);
char		*commands_get_i_command(t_commands *commands, int i);

#endif
