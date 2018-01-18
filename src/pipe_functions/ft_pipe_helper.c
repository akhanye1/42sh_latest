/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 00:47:32 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/19 07:44:46 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void			ft_append(char *buf[], t_pipe *inf)
{
	if (inf->append == TRUE && !(inf->append = FALSE))
	{
		buf[0] = "tee";
		buf[1] = "-a";
		buf[2] = inf->file;
		buf[3] = NULL;
	}
	else
	{
		buf[0] = "tee";
		buf[1] = inf->file;
		buf[2] = NULL;
	}
}

void			ft_check_for_error(int ret)
{
	if (ret == -1)
		ft_error("Failed to duplicate the file descriptor");
}
