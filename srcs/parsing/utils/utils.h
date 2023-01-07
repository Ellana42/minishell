/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:54:44 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:16 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../../../libft/includes/libft.h"

void	str_clean(char *str, int len);
int		str_cpy(char *str, char *dst);
int		str_cat(char *str, char *dst);
void	table_print(char **table);
int		table_get_size(char **table);
void	table_free(char **table);
int		str_are_equal(char *str1, char *str2);
int		str_store(char **dst, char *src, int start, int end);
int		table_init(char ***table);
int		table_add_line(char ***table, char *content);
void	mem_clean(char *ptr, int mem_size);

#endif
