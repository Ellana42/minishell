#include "export.h"

void	export_el_print(void *content)
{
	t_dict	*dict;

	dict = (t_dict *)content;
	printf("declare -x ");
	printf("%s", dict->key);
	if (dict->value)
		printf("=\"%s\"\n", dict->value);
	else
		printf("\n");
}

void	export_print(void)
{
	ft_lstiter(*glob_get_env(), &export_el_print);
}
