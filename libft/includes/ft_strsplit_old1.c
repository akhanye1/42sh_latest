/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 02:03:43 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/14 15:51:27 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	purge(char (*buffer)[MAX_BUFFER])
{
	int		i;

	i = 0;
	while (i < 1000)
	{
		ft_memset(buffer[i], '\0', MAX_BUFFER);
		i++;
	}
}

static int	fill_buffer(char const *s, char (*buffer)[MAX_BUFFER], char c)
{
	int		i;
	int		wrds;
	int		ltr;

	i = 0;
	wrds = 0;
	ltr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (ft_strlen(buffer[wrds]) > 0)
				wrds++;
			ltr = 0;
		}
		else
		{
			buffer[wrds][ltr] = s[i];
			ltr++;
		}
		i++;
	}
	if (ft_strlen(buffer[wrds]) > 0)
		wrds++;
	return (wrds);
}

char		**ft_strsplit(char const *s, char c)
{
	char	buffer[1000][MAX_BUFFER];
	int		wrds;
	int		i;
	char	**tmp;

	if (s == NULL)
		return (NULL);
	purge(buffer);
	i = 0;
	wrds = fill_buffer(s, buffer, c);
	tmp = (char**)malloc(sizeof(char*) * (wrds + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < wrds)
	{
		tmp[i] = ft_strdup(buffer[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
