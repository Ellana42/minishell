#include "../builtins/builtin.h"

// Separe l'argument fourni en une paire cle-valeur pour la variable d'environnement
// Renvoie un tableau de 2 strings contenant la clef et la valeur de la nouvelle variable d'environnement
// Ou NULL si erreur

static char **get_key_value_pair(char *arg)
{
	char	**tmp;
	char	*equal_pos;

	equal_pos = ft_strchr(arg, '=');
	tmp = malloc(sizeof * tmp * 3);
	tmp[0] = ft_substr(arg, 0, equal_pos - arg); // cle
	tmp[1] = ft_substr(equal_pos, 1, ft_strlen(equal_pos)); // valeur
	tmp[2] = NULL;
}

// Ajoute une variable d'environnement

// export : rends une variable d'environnement accessible par les processus fils de la shell courante
// VAR=value
// export VAR=value

int	export(t_data *data, char **args)
{
	char	**tmp;
	int		i;
	int		exit;

	i = 1;
	exit = EXIT_SUCCESS;

	if (!args[i])
		return (env(data, NULL));

	while (args[i])
	{
		if (!is_valid_env_var_keys(args[i]))
		{
			error_msg(); // TODO message d'erreur
			exit = EXIT_FAILURE;
		}

		else if (ft_strchr(args[i], '=') != NULL) // si on trouve un "=" dans args[i]
		{
			tmp = get_key_value_pair(args[i]);
			set_env_var(data, tmp[0], tmp[1]);
			free_str_tab(tmp);
		}
		i++;
	}
	return (exit);
}
