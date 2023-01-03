#include "lstutils.h"

void	_print_str(void *s)
{
	printf("%s,", (char *)s);
}

void	print_str_chain(t_list *lst)
{
	ft_lstiter(lst, &_print_str);
}
