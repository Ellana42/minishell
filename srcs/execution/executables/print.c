/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:48 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:58 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executables.h"

void	executables_print(t_executables *executables)
{
	ft_lstiter(*executables, &executable_print);
}
