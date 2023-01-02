/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:46 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:57 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executable.h"

int	executable_close_unused_infiles(t_executable *executable)
{
	return (_close_in_fd_table(executable->in_files, executable->in_size - 1));
}

int	executable_close_unused_outfiles(t_executable *executable)
{
	return (_close_fd_table(executable->out_files, executable->out_size - 1));
}
