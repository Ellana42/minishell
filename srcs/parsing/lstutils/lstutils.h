#ifndef LSTUTILS_H
# define LSTUTILS_H

# include "../../../libft/includes/libft.h"

void	*lst_get_i(t_list *lst, int i);
void	print_str_chain(t_list *lst);
char	*lst_get_last(t_list *lst);
t_list	*lst_get_i_lst(t_list *lst, int i);

#endif
