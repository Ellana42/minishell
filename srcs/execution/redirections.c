#include "execution.h"
#include <errno.h>

int	init_table(int **table, int size)
{
	int	i;

	i = 0;
	if (!table)
		return (0);
	while (i < size)
	{
		(*table)[i] = -1;
		i++;
	}
	return (0);
}

int	init_in_table(int ***table, int size)
{
	int	i;

	i = 0;
	if (!table)
		return (0);
	while (i < size)
	{
		(*table)[i] = (int *)malloc(sizeof(int) * 2);
		if (!(*table)[i])
			return (1);
		(*table)[i][0] = -1;
		(*table)[i][1] = -1;
		i++;
	}
	return (0);
}

int	get_in_table(t_command *cmd, int ***in_table, char **name, int *in_size)
{
	t_funnel		*funnel;
	int				i;
	t_token_type	type;

	i = 0;
	*in_size = (int )ft_lstsize(*command_get_in(cmd));
	*in_table = (int **)malloc(sizeof(int *) * (*in_size + 1));
	if (!(*in_table))
		return (1);
	if (init_in_table(in_table, *in_size))
		return (1);
	while (i < *in_size)
	{
		funnel = lst_get_i(*command_get_in(cmd), i);
		*name = funnel_get_filename(funnel);
		type = funnel_get_type(funnel);
		if (type == In)
			(*in_table)[i][0] = open(*name, O_RDONLY, 0644);
		if (type == Ina)
			execution_get_heredoc(*name, (*in_table)[i]);
		if ((*in_table)[i][0] == -1)
			return (error_msg(*name, strerror(errno), 0));
		i++;
	}
	return (0);
}

// TODO check si bonnes permissions
// TODO gérer erreur
int	get_out_table(t_command *cmd, int **out_table, int *out_size)
{
	t_funnel		*funnel;
	int				i;
	t_token_type	type;
	char			*name;

	i = 0;
	*out_size = (int )ft_lstsize(*command_get_out(cmd));
	*out_table = (int *)malloc(sizeof(int) * *out_size);
	if (!(*out_table))
		return (1);
	init_table(out_table, *out_size);
	while (i < *out_size)
	{
		funnel = lst_get_i(*command_get_out(cmd), i);
		name = funnel_get_filename(funnel);
		type = funnel_get_type(funnel);
		if (type == Out)
			(*out_table)[i] = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (type == Outa)
			(*out_table)[i] = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if ((*out_table)[i] == -1)
			return (error_msg(name, strerror(errno), 0));
		i++;
	}
	return (0);
}
