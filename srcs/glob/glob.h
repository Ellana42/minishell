/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:40 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:46 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H

# include "../../libft/includes/libft.h"
# include "../execution/int_list/int_list.h"
# include "../parsing/utils/utils.h"
# include "../parsing/lstutils/lstutils.h"
# include "../error.h"

typedef struct s_export_arg{
	char	*full_arg;
	char	*variable;
	int		operator_;
	char	*value;
}	t_export_arg;

typedef struct s_dict {
	char	*key;
	char	*value;
}	t_dict;

typedef struct s_glob {
	int			activated;
	int			exit_status;
	t_list		***env;
}	t_glob;

void		glob_destroy(void);
int			glob_is_running(void);
int			glob_init(int error, char **envp);
void		glob_print(t_bool print_env);
int			glob_get_exit_status(void);
void		glob_set_exit_status(int exit_status);
int			glob_get_state(void);
void		glob_set_state(int state);
char		*glob_getenv_var(char *var);
void		env_print(void);
int			realloc_env_vars(char **envp, t_list ***new_env);
void		env_el_destroy(void *content);
t_list		**glob_get_env(void);
char		*glob_env_get_key_i(int i);
char		*glob_env_get_val_i(int i);
t_dict		*glob_env_get_dict_i(int i);
char		*glob_getenv_var(char *var);
char		**glob_env_get_table(void);
int			glob_env_add_line(char *key, char *value);
int			glob_env_replace_var(char *var, char *new_value);
void		glob_set_env(t_list **env);
int			glob_remove_var(char *var);
int			glob_env_has_var(char *var);

#endif
