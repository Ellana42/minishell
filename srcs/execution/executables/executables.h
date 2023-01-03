#ifndef EXECUTABLES_H
# define EXECUTABLES_H

# include "../../parsing/parsing.h"
# include "../executable/executable.h"

typedef t_list	*t_executables;

int				executables_init(t_executables *exs, t_commands *cmds, int **p);
t_executables	*executables_alloc(void);
void			executables_destroy(t_executables *executables);
void			executables_print(t_executables *executables);
t_executable	*executables_get_i(t_executables *executables, int index);

#endif
