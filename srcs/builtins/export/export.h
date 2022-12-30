#ifndef EXPORT_H
# define EXPORT_H

# include "../../../libft/includes/libft.h"
# include "../../parsing/utils/utils.h"
# include "../../glob.h"

typedef struct s_export_arg{
	char	*full_arg;
	char	*variable;
	int		operator_;
	char	*value;
}	t_export_arg;

int		builtin_export(char **args_table);
void	export_arg_free(t_export_arg export_arg);
void	export_arg_print(t_export_arg export_arg);
int		export_parse_arg(char *arg, t_export_arg *export_arg);

#endif
