/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:47:49 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/10 10:01:17 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char	*append_str(char *str)
{
	char *ret;

	if (!str || !ft_strlen(str))
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(str) + 2)))
		return (NULL);
	ft_strcpy(ret, " ");
	ft_strcat(ret, str);
	ft_strcat(ret, " ");
	return (ret);
}

int		is_close_std(char *cmd)
{
	if (ft_strstr(cmd, " >&- ") || ft_strstr(cmd, " >& - ") ||
			ft_strstr(cmd, " <&- ") || ft_strstr(cmd, " <& - ") ||
			ft_strstr(cmd, " 1>&- ") || ft_strstr(cmd, " 1>& - ") ||
			ft_strstr(cmd, " 2>&- ") || ft_strstr(cmd, " 2>& - "))
		return (1);
	return (0);
}

int		is_redirect_stdtostd(char *cmd)
{
	if (ft_strstr(cmd, " >&2 ") || ft_strstr(cmd, " 1>&2 ") ||
			ft_strstr(cmd, " 2>&1 "))
		return (1);
	return (0);
}

int		is_redirect(char *cmd)
{
	if ((ft_strstr(cmd, " < ") || ft_strstr(cmd, " << ")) ||
			(ft_strstr(cmd, " > ") || ft_strstr(cmd, " >> ")) ||
			(ft_strstr(cmd, " 1> ") || ft_strstr(cmd, " 1>> ")) ||
			(ft_strstr(cmd, " 2> ") || ft_strstr(cmd, " 2>> ")) ||
			(ft_strstr(cmd, " >& ") || ft_strstr(cmd, " &> ")) ||
			(ft_strstr(cmd, " >>& ") || ft_strstr(cmd, " &>> ")))
		return (1);
	return (0);
}

int		openfile(char *file, int is_append)
{
	int fd;

	fd = -1;
	if (is_append)
	{
		if ((fd = open(file, (O_CREAT | O_WRONLY | O_APPEND),
						(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))) == -1)
			return (-1);
	}
	else
	{
		if ((fd = open(file, (O_CREAT | O_WRONLY | O_TRUNC),
						(S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH))) == -1)
			return (-1);
	}
	return (fd);
}
