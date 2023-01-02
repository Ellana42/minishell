#include "expander.h"

int	quote_var(char *var, char **result)
{
	int	i;

	i = 0;
	*result = (char *)malloc(sizeof(char) * (ft_strlen(var) + 1) * 3);
	if (!(*result))
		return (1);
	while (*var)
	{
		if (*var == '\'')
		{
			(*result)[i] = '\"';
			(*result)[i + 1] = '\'';
			(*result)[i + 2] = '\"';
			i += 2;
		}
		else if (*var == '\"')
		{
			(*result)[i] = '\'';
			(*result)[i + 1] = '\"';
			(*result)[i + 2] = '\'';
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

int	expand_variable(t_expander *expander)
{
	char	c;

	c = expander_get_char(expander);
	if (ft_isalnum(c) || c == '_')
	{
		expander_accumulate_var(expander);
		return (0);
	}
	if (acc_expanded_var(expander))
		return (1);
	expander->state = Normal;
	return (0);
}

int	expander_expand(t_expander *expander)
{
	while (!expander_eol(expander))
	{
		if (expander->state == Normal)
		{
			if (expand_normal(expander))
				return (1);
		}
		if (expander->state == SQuote)
		{
			if (expand_squote(expander))
				return (1);
		}
		if (expander->state == Variable)
		{
			if (expand_variable(expander))
				return (1);
		}
		if (expander->state == DQuote)
		{
			if (expand_dquote(expander))
				return (1);
		}
		if (expander->state == DVariable)
		{
			if (expand_dvariable(expander))
				return (1);
		}
	}
	return (0);
}

// TODO change message
char	*finish_expansion(t_expander *expander, int err)
{
	char		*expanded_command;

	if (err)
	{
		expander_destroy(expander);
		return (NULL);
	}
	if (!expander_is_empty_acc_var(expander))
		acc_expanded_var(expander);
	expanded_command = ft_strdup(expander->acc->acc);
	expander_destroy(expander);
	return (expanded_command);
}

char	*expand(char *cmd, int last_err)
{
	t_expander	*expander;

	if (!cmd)
		return (NULL);
	expander = expander_alloc();
	if (!expander)
		return (NULL);
	if (expander_init(expander, cmd, last_err))
		return (finish_expansion(expander, 1));
	if (expander_expand(expander))
		return (finish_expansion(expander, 1));
	if (expander_expand(expander))
		return (finish_expansion(expander, 1));
	return (finish_expansion(expander, 0));
}
