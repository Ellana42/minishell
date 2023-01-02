#include "expander.h"

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
