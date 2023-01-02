/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:12 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:27 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "error.h"
# include "parsing/parsing.h"
# include "execution/execution.h"
# include <stdio.h>
# include <termios.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "glob.h"
# include "../libft/includes/libft.h"

typedef struct sigaction	t_sa;

int			init_sa(t_sa *sa_c);
void		signal_reset_prompt(int signo);
void		set_signals_interactive(void);
void		signal_print_newline(int signal);
void		set_signals_noninteractive(void);

#endif
