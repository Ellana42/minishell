#include "lstutils.h"

char	*lst_get_i(t_list *lst, int i)
{
	int	j;

	j = 0;
	if (i > ft_lstsize(lst))
		return (NULL);
	while (j < i)
	{
		lst = lst->next;
		if (!lst)
			return (NULL);
		j++;
	}
	return ((char *)lst->content);
}
