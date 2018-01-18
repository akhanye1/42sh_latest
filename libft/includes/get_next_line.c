/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 23:24:44 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/30 10:23:58 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char		*get_line(char *buff, int *r, char **left, char *send)
{
	char	*temp;
	char	ttemp[ft_strlen(buff)];

	temp = send;
	*r = -1;
	if (ft_strchr(buff, '\n') == NULL)
		return (ft_strcat(temp, buff));
	*r = ft_strchr(buff, '\n') - buff;
	if (*r == 0)
		ft_strcat(temp, "");
	else
		ft_strncat(temp, buff, *r);
	if (buff[*r + 1] != '\0')
	{
		ft_strcpy(ttemp, buff + (*r + 1));
		free((*left));
		(*left) = ft_strdup(ttemp);
	}
	else
		ft_bzero((*left), ft_strlen((*left)));
	return (temp);
}

static int		freeprogmem(char **line, char **left, int r, int ronce)
{
	if (r == -1)
	{
		ft_memdel((void**)left);
		return (-1);
	}
	if (r == 0 && ronce == 0)
	{
		ft_memdel((void**)left);
		return (0);
	}
	if (ft_strlen((*line)) == 0)
	{
		free((*line));
		ft_memdel((void**)left);
		return (0);
	}
	else if (r >= 0)
		return (1);
	return (r);
}

static int		allocatemem(char **line, char **left)
{
	if ((*left) != NULL)
	{
		ft_bzero((*line), ft_strlen((*line)));
		return (0);
	}
	else
	{
		(*line) = ft_strnew(500000);
		if ((*line) == NULL)
			return (1);
		(*left) = ft_strnew(1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				r;
	static char		*left[1000];
	char			buff[BUFF_SIZE + 1];
	int				ronce;

	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	allocatemem(line, &left[fd]);
	ronce = 0;
	if (ft_strlen(left[fd]) > 0 && ronce++ < 500000)
	{
		ft_bzero((*line), ft_strlen((*line)));
		(*line) = get_line(left[fd], &r, &left[fd], (*line));
		if (r != -1)
			return (1);
		ft_bzero(left[fd], ft_strlen(left[fd]));
	}
	while (((r = read(fd, buff, BUFF_SIZE)) > 0) && ronce++ < 5000000)
	{
		buff[r] = '\0';
		(*line) = get_line(buff, &r, &left[fd], (*line));
		if (r != -1)
			return (1);
	}
	return (freeprogmem(line, &left[fd], r, ronce));
}
