#include "execution.h"

// TODO probably change return values
int get_in_table(t_command *cmd, int **in_table, char **file_name, size_t *in_size)
{
	t_funnel		*funnel;
	int 			i;
	t_token_type	type;

	i = 0;
	*in_size = ft_lstsize(*command_get_in(cmd));
	*in_table = (int *)malloc(sizeof(int) * (*in_size + 1));
	if (!(*in_table))
		return (1);
	while (i < *in_size)
	{
		funnel = lst_get_i(*command_get_in(cmd), i);
		*file_name = funnel_get_filename(funnel);
		type = funnel_get_type(funnel);
		if (type == In)
			(*in_table)[i] = open(*file_name, O_RDONLY, 0644); // TODO check si bonnes permissions
		if (type == Ina)
			(*in_table)[i] = get_here_doc(*file_name); // TODO check for return values
		if ((*in_table)[i] == -1)
			return (1); // TODO gérer erreur
		i++;
	}
	return (0);
}

int get_out_table(t_command *cmd, int **out_table, size_t *out_size)
{
	t_funnel		*funnel;
	int 			i;
	t_token_type	type;
	char 			*file_name;

	i = 0;
	*out_size = ft_lstsize(*command_get_out(cmd));
	*out_table = (int *)malloc(sizeof(int) * *out_size);
	while (i < *out_size)
	{
		funnel = lst_get_i(*command_get_out(cmd), i);
		file_name = funnel_get_filename(funnel);
		type = funnel_get_type(funnel);
		if (type == Out)
			(*out_table)[i] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644); // TODO check si bonnes permissions
		if (type == Outa)
			(*out_table)[i] = open(file_name, O_WRONLY| O_CREAT | O_APPEND, 0644);
		if ((*out_table)[i] == -1)
			return (1); // TODO gérer erreur
		i++;
	}
	return (0);
}

int clean_table_out(int **out_table, t_command *cmd)
{
	int size;
	int i;

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

int clean_table_in(int **in_table, t_command *cmd)
{
	int size;
	int i;

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
	unlink(".heredoc.tmp"); // TODO deal with output
	free(*in_table);
	return (0);
}
