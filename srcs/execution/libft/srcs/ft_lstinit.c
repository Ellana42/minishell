/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:05:54 by ellana            #+#    #+#             */
/*   Updated: 2022/03/31 13:18:09 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	**ft_lstinit(void)
{
	t_list	**lst;

	lst = (t_list **)malloc(sizeof(t_list *));
	*lst = NULL;
	return (lst);
}
