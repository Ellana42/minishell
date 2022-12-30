#ifndef UTILS_H
# define UTILS_H

# include "../../../libft/includes/libft.h"

void	str_clean(char *str, size_t len);
int		str_cpy(char *str, char *dst);
int		str_cat(char *str, char *dst);
void	mem_clean(char *ptr, size_t mem_size);
void	table_print(char **table);
int		table_get_size(char **table);
void	table_free(char **table);
int		str_are_equal(char *str1, char *str2);
int		str_store(char **dst, char *src, int start, int end);

#endif
