/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:12:32 by mkaploun          #+#    #+#             */
/*   Updated: 2022/12/04 12:03:20 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <sys/errno.h>

typedef struct s_bilist {
	void			*content;
	int				size;
	struct s_bilist	*next;
}	t_bilist;

// printing.c
int			lst_print(t_bilist *lst);

// format_conv_csudi.c
int			from_c(char c, char **str);
int			from_u(unsigned int n, char **str);
int			from_s(char *str, char **res);
int			from_d_i(int n, char **str);

// ft_itoa_u.c
char		*ft_itoa_u(unsigned int nb);

// format_conv_xp.c
int			from_hex(long int nb, char type, char **str);
int			from_p(void *ptr, char **str);
char		hex(unsigned int n, char type);
char		*reverse_str(char *str);
char		*add_prefix(char *str, char *prefix);

// copy_utils.c
char		*copy_format(const char *str, int *j, char *el);
char		*copy_str(const char *str, int *j, char *el);
int			copy_portion(const char *str, char **els, int *j);

// free_utils.c
void		*free_buf(char *buf);
void		*free_lst(t_list *lst);
void		*free_lst_buf(t_list *lst, char *buf);
void		*ft_realloc(void *ptr, size_t size);

// flag_utils.c
char		*trim(char *str, int len);
char		*left_pad(char *str, int len, char c);
char		*right_pad(char *str, int len, char c);

// utils.c
t_list		*str_to_lst(const char *str);
int			is_in_str(char c, char *str);
int			has_size(char *format);
void		*ft_charset(void *b, char c, size_t len);
int			is_type(char c);

// flags.c
char		*apply_s_flags(char *str, char *format);
char		*zero_pad(char *str, int len_target);
char		*apply_d_flags(char *str, char *format);
char		*apply_flags(char type, char *format, char *res);

t_list		*transform_formats(t_list *str_lst, va_list ap);

// ft_printf.c
int			to_smth(char type, va_list *ap, char **str);
int			transform(void	*format, va_list *ap, char **res);
t_bilist	*ft_lstmap_trans(t_list *lst, va_list *ap);
void		*format(void *content, va_list ap); //
int			ft_printf(const char *str, ...);

// bilst_utils.c

t_bilist	*ft_bilstnew(void *content, int size);
void		*ft_bilstclear(t_bilist **lst, void (*del)(void *));
t_bilist	*ft_bilstlast(t_bilist *lst);
void		ft_bilstadd_back(t_bilist **alst, t_bilist *new);

#endif