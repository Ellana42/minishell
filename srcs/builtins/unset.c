#include "../builtins/builtin.h"

// Supprime une variable ou une fonction de l'environnement
// Dès lors, cette variable n'est plus accessible

// Check si la cle est un nom valide de variable d'environnement
// Renvoie vrai si la cle ne contient que des caracteres alphanumeriques ou "_"
// Ou faux sinon

bool	is_valid_env_var_keys(char *var)
{
	
}

// Supprime les variables d'environnement avec les cles donnees
// Apres avoir verifie s'il s'agit de cles valides
// Ne fait rien si la cle n'est pas dans l'environnement
// Retourne 0 si tous les arguments ont ete supprimes avec succes
// Ou 1 si un ou plusieurs arguments n'ont pas pu etre supprimes

int	unset(t_data *data, char **args)
{
	int	i;
	int	j;

	i = 1;

	while (args[i])
	{
		if (is_valid_env_var_keys(args[i]) == 0 || ft_strchr(args[i], '=') != NULL)
		{

		}
	}
}
