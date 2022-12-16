#include "../execution/execution.h"

// pwd : affiche le chemin absolu du repertoire de travail actuel

// char *getcwd(char *buf, size_t size);
// Recupere le chemin du repertoire de travail courant
// - buf : pointeur sur tableau de chars, constitue du path
// - size : taille de buf

#define MAX_PATH 4096

typedef struct s_data
{
	char	*working_directory;
}	t_data;

int	pwd(t_data *data, char **args)
{
	char	*buf[MAX_PATH]
}
