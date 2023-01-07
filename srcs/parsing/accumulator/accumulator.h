/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accumulator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:54:43 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:13 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCUMULATOR_H
# define ACCUMULATOR_H

# include "../../../libft/includes/libft.h"
# include "../utils/utils.h"

typedef struct s_acc {
	char	*acc;
	char	*ptr;
	int		i;
	int		size;
	t_bool	is_empty;
}	t_acc;

void	acc_reset(t_acc *acc);
int		acc_is_empty(t_acc *acc);
int		acc_accumulate(t_acc *acc, char c);
int		acc_concat(t_acc *acc, char *str);
t_acc	*acc_alloc(void);
int		acc_init(t_acc *acc, size_t size);
void	acc_dispose(t_acc *acc);
void	acc_free(t_acc *acc);
void	acc_destroy(t_acc *acc);
int		acc_move(t_acc *acc);
char	*acc_get(t_acc	*acc);
int		acc_set_not_empty(t_acc	*acc);

#endif
