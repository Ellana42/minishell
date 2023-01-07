/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_set_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:39 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:45 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

int	glob_env_add_line(char *key, char *value)
{
	t_dict			*new_el;
	t_list			*new_el_lst;

	new_el = (t_dict *)malloc(sizeof(t_dict));
	if (!new_el)
		return (1);
	new_el->key = ft_strdup(key);
	if (value)
		new_el->value = ft_strdup(value);
	else
		new_el->value = NULL;
	new_el_lst = ft_lstnew((void *)new_el);
	if (!new_el_lst)
		return (1);
	ft_lstadd_back(glob_get_env(), new_el_lst);
	return (0);
}
