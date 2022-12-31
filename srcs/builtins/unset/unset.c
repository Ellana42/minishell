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
// // tmp = QT_ACCESSIBILITY=

int	get_env_var_index(char **env, char *var)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin(var, "=");
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

// Supprime la variable a un certain index de l'environnement
// Retourne (-1) si succes
// 0 si mauvais index ou erreur d'allocation memoire

bool	remove_env_var(char **env, int index)
{
	int	i;

	if (index > env_var_nbr(env))
		return (false);
	free(env[index]);
	i = index;
	while (env[i + 1])
	{
		env[i] = ft_strdup(env[i + 1]);
		if (!env[i])
			return (1);
		free(env[i + 1]);
		i++;
	}
	env[i] = NULL;
	if (!env)
		return (false);
	return (true);
}

// Supprime les variables d'environnement avec les cles donnees
// Apres avoir verifie s'il s'agit de cles valides
// Ne fait rien si la cle n'est pas dans l'environnement
// Retourne 0 si tous les arguments ont ete supprimes avec succes
// Ou 1 si un ou plusieurs arguments n'ont pas pu etre supprimes
// TODO check error print

int	unset(char **args)
{
	int		i;
	int		exit;

	exit = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		if (is_valid_env_var(args[i]) == 0 || ft_strchr(args[i], '=') != NULL)
		{
			if (args[i][0] != '\0')
			{
				printf("minishell: unset:");
				printf(" `%s': not a valid identifier\n", args[i]);
			}
			exit = EXIT_FAILURE;
		}
		else
		{
			glob_remove_var(args[i]);
		}
		i++;
	}
	return (exit);
}
