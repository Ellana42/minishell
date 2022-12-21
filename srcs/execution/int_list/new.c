#include "int_list.h"

t_intlist	**intlstinit(void)
{
	t_intlist	**lst;

	lst = (t_intlist **)malloc(sizeof(t_intlist *));
	*lst = NULL;
	return (lst);
}

t_intlist	*intlstnew(int content)
{
	t_intlist	*out;

	out = (t_intlist *)malloc(sizeof(t_intlist));
	if (!out)
		return (NULL);
	(*out).content = content;
	(*out).next = NULL;
	return (out);
}

t_intlist	*intlstlast(t_intlist *lst)
{
	while ((*lst).next)
		lst = (*lst).next;
	return (lst);
}

void	intlstadd_back(t_intlist **alst, t_intlist *new)
{
	t_intlist	*last;

	if (!(*alst))
		*alst = new;
	else
	{
		last = intlstlast(*alst);
		(*last).next = new;
	}
}

int	intlst_pop(t_intlist **lst, int *popped)
{
	t_intlist	*second_lst;
	int			content;

	if (!lst)
		return (1);
	if (!(*lst))
		return (1);
	second_lst = (*lst)->next;
	content = (*lst)->content;
	free(*lst);
	*lst = second_lst;
	*popped = content;
	return (0);
}
