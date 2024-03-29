/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:51:56 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:00 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <termios.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/includes/libft.h"

typedef struct sigaction	t_sa;

int		error_msg(char *cmd, char *issue, int err);
int		error_msg2(char *cmd, char *cmd2, char *issue, int err);
int		error_msg3(char *msg, int err);
int		set_errnum(int *error, int error_value, int return_value);
void	write_to_stderr(char *str);

#endif
