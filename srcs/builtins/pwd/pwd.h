/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:13 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:29 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PWD_H
# define PWD_H

# include "../../../libft/includes/libft.h"
# include "../../glob.h"
# define PATH_MAX 4096

int	pwd_builtin(char **args);

#endif
