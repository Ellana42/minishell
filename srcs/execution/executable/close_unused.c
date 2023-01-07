/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:47 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:54:03 by mkaploun         ###   ########.fr       */
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
