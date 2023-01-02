#ifndef CD_H
# define CD_H

# include <stdio.h>
# include "../../parsing/utils/utils.h"
# include <sys/stat.h>
# include "../../glob.h"
# include "../../error.h"
# include <errno.h>

# define PATH_MAX 4096

int	cd(char **args_table);

#endif
