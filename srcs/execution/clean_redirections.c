#include "execution.h"

int	clean_table_out(int **out_table, t_command *cmd)
{
	int	size;
	int	i;

	if (!cmd)
		return (0);
	size = ft_lstsize(*command_get_out(cmd));
	i = 0;
	while (i < size)
	{
		if ((*out_table)[i] >= 0)
			close((*out_table)[i]);
		i++;
	}
	free(*out_table);
	return (0);
}

int	clean_table_in(int **in_table, t_command *cmd)
{
	int	size;
	int	i;

	if (!cmd)
		return (0);
	size = ft_lstsize(*command_get_in(cmd));
	i = 0;
	while (i < size)
	{
		if ((*in_table)[i] >= 0)
			close((*in_table)[i]);
		i++;
	}
	free(*in_table);
	return (0);
}
