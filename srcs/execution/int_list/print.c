#include "int_list.h"

void	int_lstiter(t_intlist *lst, void (*f)(int))
{
	while (lst)
	{
		f((*lst).content);
		lst = (*lst).next;
	}
}

void	_int_print(int i)
{
	printf("%d, ", i);
}

void	int_lstprint(t_intlist *lst)
{
	int_lstiter(lst, &_int_print);
	printf("\n");
}
