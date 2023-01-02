/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:13 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:29 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include <stdio.h>
# include "../../parsing/utils/utils.h"
# include <sys/stat.h>
# include "../../glob.h"
# include "../../error.h"
# include <errno.h>

# define PATH_MAX 4096

int	cd(char **args_table);

#endif
