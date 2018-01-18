/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:53:10 by nmbotho           #+#    #+#             */
/*   Updated: 2017/11/07 10:08:57 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		ft_validate(char **cmd)
{
	int i;

	i = 0;
	if (cmd)
	{
		while (cmd[i])
		{
			if (ft_strlen(cmd[i]) > 4096)
			{
				ft_error("exceeded max input");
				return (0);
			}
			i++;
		}
		if (i > 4096)
		{
			ft_error("exceeded max number of arguments");
			return (0);
		}
		return (1);
	}
	return (0);
}
