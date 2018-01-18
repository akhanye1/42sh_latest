/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:02:24 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/17 10:29:27 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int			logical_op_count(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '|' && str[i + 1] == '|') ||
				(str[i] == '&' && str[i + 1] == '&'))
			count++;
		i++;
	}
	return (count);
}

char		**andor_management(char *str, char **env, int *val)
{
	int		count;
	t_andor	*head;

	*val = 1;
	count = logical_op_count(str);
	head = chaining(str, count);
	env = command_list(head, env);
	return (env);
}
