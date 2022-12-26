#ifndef INT_LIST_H
# define INT_LIST_H

# include "../../../libft/includes/libft.h"

typedef struct s_intlist {
	int					content;
	struct s_intlist	*next;
}	t_intlist;

t_intlist	**intlstinit(void);
t_intlist	*intlstnew(int content);
t_intlist	*intlstlast(t_intlist *lst);
void		intlstadd_back(t_intlist **alst, t_intlist *newlst);
int			intlst_pop(t_intlist **lst, int *popped);
void		int_lstiter(t_intlist *lst, void (*f)(int));
void		_int_print(int i);
void		int_lstprint(t_intlist *lst);
void		int_lstclear(t_intlist **lst);

#endif
