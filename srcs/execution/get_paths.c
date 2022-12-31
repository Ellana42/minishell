#include "execution.h"

// Parcourt l'envp pour trouver la variable d'environnement PATH
// Renvoie la string contenant les différents array_of_paths de PATH

static char	*extract_path(char **envp)
{
	return (glob_getenv_var("PATH"));
}

// Ajoute un "/" à la fin de chaque paths pour les rendres parcourables 
// et executables
// Stocke ces différents paths dans un **tableau qu'on retourne
static char	**make_executable_paths(char **array_of_paths)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (array_of_paths[i])
	{
		tmp = array_of_paths[i];
		array_of_paths[i] = ft_strjoin(array_of_paths[i], "/");
		free_strs(tmp, NULL);
		i++;
	}
	return (array_of_paths);
}

// Stocke la string PATH dans une variable en la récuperant via extract_path()
// Découpe cette string en fonction du ':', 
// et stocke ces strings dans **array_of_paths
// Ajoute un '/' à la fin de chaque paths de **array_of_paths 
// via make_executable_paths()
// Retourne ce tableau de paths

static char	**fill_array_of_paths(char **envp)
{
	char	*env_path_str;
	char	**array_of_paths;

	env_path_str = extract_path(envp);
	if (!env_path_str)
		return (NULL);
	array_of_paths = ft_split(env_path_str, ':');
	free_strs(env_path_str, NULL);
	if (!array_of_paths)
		return (NULL);
	array_of_paths = make_executable_paths(array_of_paths);
	if (!array_of_paths)
		return (NULL);
	return (array_of_paths);
}

// Cherche le path contenant les fichiers binaires nous permettant
// d'executer les commandes entrées par l'user
// Vérifie si le path existe et qu'il est accessible (F_OK) 
// pour être executer (X_OK)
// Retourne ce fameux path

static char	*get_valid_path(char *cmd, char **array_of_paths, int *errnum)
{
	int		i;
	char	*path_ultime;

	i = 0;
	path_ultime = NULL;
	while (array_of_paths[i])
	{
		path_ultime = ft_strjoin(array_of_paths[i], cmd);
		if (!path_ultime)
		{
			free_strs(NULL, array_of_paths);
			error(msg("unexpected error", "", "", 1));
		}
		if (is_dir(path_ultime))
		{
			msg("Is a directory", ": ", cmd, 1);
			*errnum = 126;
		}
		else if (access(path_ultime, F_OK | X_OK) == 0)
			return (path_ultime);
		free_strs(path_ultime, NULL);
		i++;
	}
	return (NULL);
}

// Obtient le path de la commande fournie par l'user à partir des 
// variables d'environnement
// Retourne le path de la commande ou NULL si aucun path n'a été trouvé

char	*get_user_cmd(char *cmd, char **envp, int *errnum)
{
	char	**env_paths;
	char	*path_ultime;

	if (is_dir(cmd))
	{
		msg(cmd, ": ", "Is a directory", 1);
		*errnum = 126;
		return (NULL);
	}
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	env_paths = fill_array_of_paths(envp);
	if (!env_paths)
		return (NULL);
	path_ultime = get_valid_path(cmd, env_paths, errnum);
	if (!path_ultime)
	{
		printf("%s: command not found\n", cmd);
		*errnum = 127;
	}
	free_strs(NULL, env_paths);
	return (path_ultime);
}
