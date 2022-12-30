#include "utils.h"

int	table_init(char ***table)
{
	*table = (char **)malloc(sizeof(char *) * 1);
	if (!(*table))
		return (1);
	(*table)[0] = NULL;
	return (0);
}

int	table_add_line(char ***table, char *content)
{
	char	**new_table;
	int		size_old_table;
	int		i;

	size_old_table = table_get_size(*table);
	new_table = (char **)malloc(sizeof(char *) * (size_old_table + 2));
	if (!new_table)
		return (1);
	i = 0;
	while (i < size_old_table)
	{
		new_table[i] = (*table)[i];
		i++;
	}
	new_table[i] = ft_strdup(content);
	new_table[i + 1] = NULL;
	if (!new_table[i])
	{
		table_free(new_table);
		return (1);
	}
	free(*table);
	*table = new_table;
	return (0);
}

void	table_free(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	table_print(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (table[i])
	{
		printf("%d : %s\n", i, table[i]);
		i++;
	}
	printf("%d : %s\n", i, table[i]);
}

int	table_get_size(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return (-1);
	while (table[i])
		i++;
	return (i);
}
