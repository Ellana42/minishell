#include "unset.h"
// Supprime une variable ou une fonction de l'environnement
// Dès lors, cette variable n'est plus accessible

// Check si la cle est un nom valide de variable d'environnement
// Renvoie vrai si la cle ne contient que des caracteres alphanumeriques ou "_"
// Ou faux sinon

// QT_ACCESSIBILITY=1

bool	is_valid_env_var(char *var)
{
	int	i;

	i = 0;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
		return (false);
	i++;
	while (var[i] && var[i] != '=')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

// Recherche une certaine variable dans l'environnement
// Retourne l'index de la variable correspondant a la string passee en parametre
// La string donnee doit etre un nom de variable complet
// Renvoie (-1) si la string est introuvable dans l'environnement

int	get_env_var_index(char **env, char *var)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin(var, "="); // tmp = QT_ACCESSIBILITY=

	if (!tmp)
		return (-1);

	i = 0;

	while (env[i])
	{
		if (ft_strncmp(tmp, env[i], ft_strlen(tmp)) == 0)
		{
			free(tmp);
			return (i);
		}
		i++;
	}
	free(tmp);
	return (-1);
}

// Compte le nombre de variables presents a l'origine dans l'environnement
// Retourne ce nombre

int	env_var_nbr(char **env)
{
	int	i;
	i = 0;

	while (env && env[i])
		i++;
	return (i);
}

// Re-alloue de la memoire pour un nouvel env
// Retourne un pointeur sur le nouvel env ou NULL

char	**realloc_env_vars(char **envp)
{
	char	**new_env;
	int		i;

	new_env = (char **)malloc(sizeof(char *) * (table_get_size(envp) + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
		{
			table_free(new_env);
			return (NULL);
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

// Supprime la variable a un certain index de l'environnement
// Retourne (-1) si succes
// 0 si mauvais index ou erreur d'allocation memoire

bool	remove_env_var(t_data *data, int index)
{
	int	i;
	int	count;

	if (index > env_var_nbr(data->env))
		return (false);

	free(data->env[index]);

	i = index;
	count = index;

	while (data->env[i + 1])
	{
		data->env[i] = ft_strdup(data->env[i + 1]);
		free(data->env[i + 1]);
		count++;
		i++;
	}

	/* data->env = realloc_env_vars(data); */

	if (!data->env)
		return (false);

	return (true);
}

// Supprime les variables d'environnement avec les cles donnees
// Apres avoir verifie s'il s'agit de cles valides
// Ne fait rien si la cle n'est pas dans l'environnement
// Retourne 0 si tous les arguments ont ete supprimes avec succes
// Ou 1 si un ou plusieurs arguments n'ont pas pu etre supprimes

int	unset(t_data *data, char **args)
{
	int	i;
	int	index;
	int	exit;

	exit = EXIT_SUCCESS;
	i = 1;

	while (args[i])
	{
		if (is_valid_env_var(args[i]) == 0 || ft_strchr(args[i], '=') != NULL)
		{
			printf("Not a valid identifier\n");
			exit = EXIT_FAILURE;
		}
		else
		{
			index = get_env_var_index(data->env, args[i]);

			if (index != -1)
				remove_env_var(data, index);
		}
		i++;
	}
	return (exit);
}
