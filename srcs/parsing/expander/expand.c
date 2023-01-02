#include "expander.h"

int	expand_errnum(t_expander *expander)
{
	char	*err_num;

	err_num = ft_itoa(expander->last_err);
	if (expander_acc_concat(expander, err_num))
		return (1);
	free(err_num);
	expander_move_cursor(expander);
	expander_move_cursor(expander);
	return (0);
}

// TODO check
int	expand_single_dollar(t_expander *expander)
{
	char	c;

	c = expander_get_next_char(expander, 1);
	if (c != '\'' && c != '\"')
		expander_accumulate(expander);
	else
		expander_move_cursor(expander);
	return (0);
}

int	expand_normal(t_expander *expander)
{
	if (expander_get_char(expander) == '$')
	{
		if (expander_get_next_char(expander, 1) == '?')
			return (expand_errnum(expander));
		if (!ft_isalnum(expander_get_next_char(expander, 1)))
			return (expand_single_dollar(expander));
		expander->state = Variable;
		expander_move_cursor(expander);
		return (0);
	}
	if (expander_get_char(expander) == '\'')
	{
		expander->state = SQuote;
		expander_accumulate(expander);
		return (0);
	}
	if (expander_get_char(expander) == '\"')
	{
		expander->state = DQuote;
		expander_accumulate(expander);
		return (0);
	}
	expander_accumulate(expander);
	return (0);
}

int	expand_squote(t_expander *expander)
{
	if (expander_get_char(expander) == '\'')
	{
		expander->state = Normal;
		expander_accumulate(expander);
		return (0);
	}
	expander_accumulate(expander);
	return (0);
}

int	expand_dquote(t_expander *expander)
{
	if (expander_get_char(expander) == '\"')
	{
		expander->state = Normal;
		expander_accumulate(expander);
		return (0);
	}
	if (expander_get_char(expander) == '$')
	{
		if (expander_get_next_char(expander, 1) == '?')
			return (expand_errnum(expander));
		if (!ft_isalnum(expander_get_next_char(expander, 1)))
			return (expand_single_dollar(expander));
		expander->state = DVariable;
		expander_move_cursor(expander);
		return (0);
	}
	expander_accumulate(expander);
	return (0);
}
