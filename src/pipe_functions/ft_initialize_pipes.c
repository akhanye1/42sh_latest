/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_pipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:15:34 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/18 14:06:34 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

/*
** Replace wherever the is a return -1 with error function including the errorno
*/

int		ft_initialize_pipes(int input, int output)
{
	if (input != 0)
	{
		dup2(input, 0);
		if (close(input) == -1)
			return (-1);
	}
	if (output != 1)
	{
		dup2(output, 1);
		if (close(output) == -1)
			return (-1);
	}
	return (1);
}
