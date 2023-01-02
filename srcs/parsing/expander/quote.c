#include "expander.h"

void	add_quotes(char quote, char **result, int i)
{
	if (quote == '\'')
	{
		(*result)[i] = '\"';
		(*result)[i + 1] = '\'';
		(*result)[i + 2] = '\"';
	}
	else if (quote == '\"')
	{
		(*result)[i] = '\'';
		(*result)[i + 1] = '\"';
		(*result)[i + 2] = '\'';
	}
}

int	quote_var(char *var, char **result)
{
	int	i;

	i = 0;
	*result = (char *)malloc(sizeof(char) * (ft_strlen(var) + 1) * 3);
	if (!(*result))
		return (1);
	while (*var)
	{
		if (*var == '\'' || *var == '\"')
		{
			add_quotes(*var, result, i);
			i += 2;
		}
		else
			(*result)[i] = *var;
		i++;
		var++;
	}
	(*result)[i] = '\0';
	return (0);
}

int	acc_expanded_var(t_expander *expander)
{
	char	*var;
	char	*quoted_var;

	var = glob_getenv_var(acc_get(expander->acc_var));
	if (!var)
		return (0);
	if (quote_var(var, &quoted_var))
		return (1);
	if (quoted_var)
	{
		if (expander_acc_concat(expander, quoted_var))
			return (1);
		free(quoted_var);
	}
	expander_reset_acc_var(expander);
	return (0);
}

int	acc_expanded_dvar(t_expander *expander)
{
	char	*var;

	var = glob_getenv_var(acc_get(expander->acc_var));
	if (!var)
		return (0);
	else
	{
		if (expander_acc_concat(expander, var))
			return (1);
	}
	expander_reset_acc_var(expander);
	return (0);
}

int	expand_dvariable(t_expander *expander)
{
	char	c;

	c = expander_get_char(expander);
	if (ft_isalnum(c) || c == '_')
	{
		expander_accumulate_var(expander);
		return (0);
	}
	if (acc_expanded_dvar(expander))
		return (1);
	expander->state = DQuote;
	return (0);
}
