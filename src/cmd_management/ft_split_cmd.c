/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:40:04 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/23 17:42:17 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	ft_split_cmd(char *s)
{
	int		i;
	char	**array;
	char	**cmds;
	int		len;

	i = 0;
	len = 0;
	cmds = NULL;
	if (s)
	{
		array = ft_strsplit(s, ';');
		if ((len = ft_count2d((void**)array)))
		{
			cmds = (char **)malloc(sizeof(char*) * len + 1);
			while (array[i])
			{
				cmds[i] = ft_normmilize_cmd(array[i]);
				i++;
			}
			cmds[i] = NULL;
			ft_free2d((void**)array);
		}
		ft_handle_pipes(cmds);
		ft_free2dsafe((void***)&cmds);
	}
}
