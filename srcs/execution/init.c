/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:32:14 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/10 15:03:08 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// "Mise à nue" de notre structure
// On pourra call cette fonction avant d'utiliser les valeurs de notre structure
// -1 pour les variables qui ne sont pas des strings car 0 est une valeur possible de fd

static t_data	clean_init_struct(void)
{
	t_data	data;

	data.envp = NULL;
    data.commands = NULL;

	return (data);
}

// Initialise la structure en fonction des arguments fournis par l'user
// Créer les pipes pour chaque processus

t_data	init_struct(t_commands *commands, char **envp)
{
	t_data	data;
	data = clean_init_struct();

	data.envp = envp;
    data.commands = commands;

	return (data);
}
