/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:33:26 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/02 00:50:53 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_getlines(char *filename)
{
	int		fd;
	int		nlines;
	char	*lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	nlines = 0;
	lines = NULL;
	while (get_next_line(fd, &lines) > 0)
		nlines++;
	close(fd);
	return (nlines);
}
