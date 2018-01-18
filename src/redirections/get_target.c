/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:54:30 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/09 10:00:04 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char		*get_target(char *cmd, char *target)
{
	int		i;
	char	*ret;
	char	*app_str;
	char	**tmp;

	if (!(tmp = ft_cmd_processor(cmd)))
		return (NULL);
	i = -1;
	while (tmp[++i])
	{
		if (ft_strstr((app_str = append_str(tmp[i])), target))
		{
			if (countlist(&tmp[i + 1]) && !is_redirect(tmp[i + 1]))
			{
				ret = ft_strdup(tmp[i + 1]);
				ft_free2d((void**)tmp);
				return (ret);
			}
			ft_free2d((void**)tmp);
			ft_putstr_fd("shell: Missing name for redirect\n", 2);
			return (NULL);
		}
	}
	ft_free2d((void**)tmp);
	return (NULL);
}
