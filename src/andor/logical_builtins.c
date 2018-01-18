/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:12:19 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/17 11:02:09 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char		**run_logical(char *str, char **env, int *val)
{
	char	**arr;
	int		check;

	check = *val;
	if (ft_strncmp(str, "echo", 4) == 0)
	{
		echo_vpipe(str, env, val);
		*val = 0;
		return (env);
	}
	*val = -1;
	if (*val <= 0)
	{
		arr = ft_strsplit(str, ' ');
		if (check == -7 || *val == -1)
			*val = -7;
		process2(str, env, val);
		free_2d_array((void**)arr);
	}
	return (env);
}
