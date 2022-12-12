#include "command.h"

void	_funnel_print(void *f)
{
	t_funnel	*funnel;

	funnel = (t_funnel *)f;
	printf("%s:", funnel->filename);
	printf("%d,", funnel->type);
}

void	print_funnel_chain(t_list *lst)
{
	ft_lstiter(lst, &_funnel_print);
}
