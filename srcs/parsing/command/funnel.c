#include "command.h"

void	_funnel_print(void *f)
{
	t_funnel	*funnel;

	funnel = (t_funnel *)f;
	printf("%s:", funnel->filename);
	if (funnel->type == Out)
		printf("out,");
	else if (funnel->type == Outa)
		printf("outa,");
	else if (funnel->type == In)
		printf("in,");
	else if (funnel->type == Ina)
		printf("ina,");
}

void	print_funnel_chain(t_list *lst)
{
	ft_lstiter(lst, &_funnel_print);
}
