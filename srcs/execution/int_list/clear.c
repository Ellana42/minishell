#include "int_list.h"

void	int_lstclear(t_intlist **lst)
{
	t_intlist	*el;
	t_intlist	*next_el;

	next_el = NULL;
	el = *lst;
	while (el)
	{
		next_el = (*el).next;
		free(el);
		el = next_el;
	}
	*lst = NULL;
}
