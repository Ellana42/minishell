#include "../includes/libft.h"

void	*ft_lstget_i(t_list *lst, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (!lst)
			return (NULL);
		lst = lst->next;
		i++;
	}
	if (!lst)
		return (NULL);
	return (lst->content);
}
