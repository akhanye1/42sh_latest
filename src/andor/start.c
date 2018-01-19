/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:02:24 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/19 14:14:17 by nmbotho          ###   ########.fr       */
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

int			parse_checker(char *str)
{
	char	**checker;

	checker = ft_strsplit(str, ' ');
	if ((checker[0][0] == '|' && checker[1][0] == '&') ||
		(checker[0][0] == '&' && checker[1][0] == '|') ||
		(checker[0][0] == '|' && checker[1][0] == '|') ||
		(checker[0][0] == '&' && checker[1][0] == '&'))
	{
		ft_putendl("42sh: parse error");
		free_2d_array((void**)checker);
		return (-1);
	}
	free_2d_array((void**)checker);
	return (1);
}

char		**andor_management(char *str, char **env, int *val)
{
	int		count;
	t_andor	*head;

	*val = 1;
	if (parse_checker(str) == -1)
		return (env);
	count = logical_op_count(str);
	head = chaining(str, count);
	env = command_list(head, env);
	return (env);
}
