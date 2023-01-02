#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "../accumulator/accumulator.h"
# include "../../glob.h"

typedef enum s_state_expander{
	Normal = 0,
	SQuote = 1,
	Variable = 2,
	DQuote = 3,
	DVariable = 4,
}	t_state_expander;

typedef struct s_expander{
	char				*command;
	int					size;
	char				*cmd_ptr;
	int					cmd_i;
	t_acc				*acc;
	t_acc				*acc_var;
	t_state_expander	state;
	int					last_err;
}	t_expander;

t_expander	*expander_alloc(void);
int			expander_init(t_expander *expander, char *cmd, int last_err);
void		expander_dispose(t_expander *expander);
void		expander_free(t_expander *expander);
int			expander_move_cursor(t_expander *expander);
int			expander_move_accumulator(t_expander *expander);
char		expander_get_char(t_expander *expander);
char		expander_get_last_char(t_expander *expander);
char		expander_get_next_char(t_expander *expander, int s);
int			expander_eol(t_expander *expander);
void		expander_reset_acc(t_expander *expander);
int			expander_is_empty_acc(t_expander *expander);
int			expander_accumulate(t_expander *expander);
int			expander_acc_concat(t_expander *expander, char *str);
int			expander_accumulate_var(t_expander *expander);
void		expander_reset_acc_var(t_expander *expander);
int			expander_is_empty_acc_var(t_expander *expander);
void		expander_destroy(t_expander *expander);
int			expander_move_cursor_two(t_expander *expander);
int			expander_set_not_empty_acc(t_expander *expander);
char		*expand(char *cmd, int last_err);
int			expand_errnum(t_expander *expander);
int			expand_single_dollar(t_expander *expander);
int			expand_normal(t_expander *expander);
int			expand_squote(t_expander *expander);
int	expand_dquote(t_expander *expander);

#endif
