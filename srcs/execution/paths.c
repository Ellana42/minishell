/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:45:04 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/03 16:21:20 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Parcourt l'envp pour trouver la variable d'environnement PATH
// Renvoie la string contenant les différents array_of_paths de PATH

static char *extract_path(char **envp)
{
	char *path;
	int i;

	path = NULL;
	i = 0;

	while (envp[i] != NULL && envp[i][0] != '\0')
	{
		path = ft_strnstr(envp[i], "PATH=", 5);

		if (path != NULL)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			break;
		}
		i++;
	}
	return (path);
	// path = /Library/Frameworks/Python.framework/Versions/3.10/bin:/usr/local/bin:
	//		  /System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin
}

// Ajoute un "/" à la fin de chaque paths pour les rendres parcourables et executables
// Stocke ces différents paths dans un **tableau qu'on retourne

static char **make_executable_paths(char **array_of_paths)
{
	int i;
	char *tmp;

	i = 0;
	tmp = NULL;

	while (array_of_paths[i] != '\0')
	{
		tmp = array_of_paths[i];
		array_of_paths[i] = ft_strjoin(array_of_paths[i], "/");
		free_strs(tmp, NULL);
		i++;
	}
	return (array_of_paths);
}

// Stocke la string PATH dans une variable en la récuperant via extract_path()
// Découpe cette string en fonction du ':', et stocke ces strings dans **array_of_paths
// Ajoute un '/' à la fin de chaque paths de **array_of_paths via make_executable_paths()
// Retourne ce tableau de paths

static char	**fill_array_of_paths(char **envp)
{
	char *path_str;
	char **array_of_paths;

	path_str = extract_path(envp);

	if (path_str == NULL)
		return (NULL);

	array_of_paths = ft_split(path_str, ':');

	free_strs(path_str, NULL);

	if (array_of_paths == NULL)
		return (NULL);

	array_of_paths = make_executable_paths(array_of_paths);

	if (array_of_paths == NULL)
		return (NULL);

	return (array_of_paths);
}

// Cherche le path contenant les fichiers binaires nous permettant
// d'executer les commandes entrées par l'user
// Vérifie si le path existe et qu'il est accessible (F_OK) pour être executer (X_OK)
// Retourne ce fameux path

static char *get_valid_path(char *cmd, char **array_of_paths)
{
	char	*path_ultime;
	int		i;

	path_ultime = NULL;
	i = 0;

	while (array_of_paths[i] != '\0')
	{
		path_ultime = ft_strjoin(array_of_paths[i], cmd);
		if (path_ultime == NULL)
		{
			free_strs(NULL, array_of_paths);
			error(msg("unexpected error", "", "", 1), NULL);
		}

		if (access(path_ultime, F_OK | X_OK) == 0)
			return (path_ultime);

		free_strs(path_ultime, NULL);
		i++;
	}
	return (NULL);
}

// Obtient le path de la commande fournie par l'user à partir des variables d'environnement
// Retourne le path de la commande ou NULL si aucun path n'a été trouvé

char	*get_user_cmd(char *cmd, t_data *data)
{
	char **env_paths;
	char *path_ultime;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));

	env_paths = fill_array_of_paths(data->envp);

	if (env_paths == NULL)
		return (NULL);

	path_ultime = get_path_ultime(cmd, env_paths);

	if (path_ultime == NULL)
		msg("command not found", ": ", data->argv[data->child + 2], 1);

	free_strs(NULL, env_paths);
	return (path_ultime);
}
