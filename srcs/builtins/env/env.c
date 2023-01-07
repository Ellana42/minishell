/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:44 by ellana            #+#    #+#             */
/*   Updated: 2023/01/07 11:54:02 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// env : permet de lister les variables d'environnement
// À gérer sans options ni arguments
int	env(char **args)
{
	if (table_get_size(args) > 1)
	{
		error_msg("env", "too many arguments", 0);
		return (1);
	}
	env_print();
	return (0);
}
