#ifndef EXPORT_H
# define EXPORT_H

# include "../../../libft/includes/libft.h"
# include "../../parsing/accumulator/accumulator.h"
# include "../../parsing/tokenizer/token.h"

typedef struct s_export_arg{
	char	*variable;
	int		operator_;
	char	*value;
}	t_export_arg;

int	builtin_export(char **args_table);

#endif
