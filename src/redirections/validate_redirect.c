/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 23:40:51 by mkgosise          #+#    #+#             */
/*   Updated: 2017/10/01 16:39:49 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static char	*ft_findstr(char *str, char *find)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], find, (len = ft_strlen(find))) == 0)
			return (&str[i + len]);
		i++;
	}
	return (NULL);
}

static int	validate_part_1(char *cmd)
{
	char *str;

	if ((str = ft_findstr(cmd, " 2>> ")) ||
			(str = ft_findstr(cmd, " 2> ")))
	{
		if (ft_strstr(str, " 2> ") || ft_strstr(str, " 2>> "))
			return (0);
	}
	if ((str = ft_findstr(cmd, " > ")) ||
			(str = ft_findstr(cmd, " >> ")) ||
			(str = ft_findstr(cmd, " 1> ")) ||
			(str = ft_findstr(cmd, " 1>> ")))
	{
		if (ft_strstr(str, " > ") || ft_strstr(str, " >> ") ||
				ft_strstr(str, " 1> ") || ft_strstr(str, " 1>> "))
			return (0);
	}
	else if ((str = ft_findstr(cmd, " << ")) ||
			(str = ft_findstr(cmd, " < ")))
	{
		if (ft_strstr(str, " << ") || ft_strstr(str, " < "))
			return (0);
	}
	return (1);
}

static int	validate_part_2(char *cmd)
{
	char *str;

	if (((str = ft_findstr(cmd, " &> ")) ||
			(str = ft_findstr(cmd, " >& "))) &&
			!ft_strstr(cmd, " >& - "))
	{
		if (ft_strstr(str, " &> ") || ft_strstr(str, " >& "))
			return (0);
	}
	if ((str = ft_findstr(cmd, " >&2 ")) ||
			(str = ft_findstr(cmd, " 1>&2 ")) ||
			(str = ft_findstr(cmd, " 2>&1 ")))
	{
		if (ft_strstr(str, ">&2 ") || ft_strstr(str, "1>&2 ") ||
				ft_strstr(str, "2>&1 "))
			return (0);
	}
	return (1);
}

int			validate_redirect(char *cmd)
{
	if (!validate_part_1(cmd) || !validate_part_2(cmd))
		return (0);
	return (1);
}
