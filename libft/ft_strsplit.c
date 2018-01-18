/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:38:29 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/19 13:32:26 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countitems(char const *s, char c)
{
	int i;
	int itms;
	int b;

	i = 0;
	b = 0;
	itms = 0;
	while (s[i])
	{
		if (s[i] != c && b == 0)
		{
			itms++;
			b = 1;
		}
		if (b == 1 && s[i] == c)
			b = 0;
		i++;
	}
	return (itms);
}

static char	*getitem(char const *s, char c)
{
	int		i;
	char	*ret;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ret = (char*)malloc(sizeof(ret) * (i + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	**append(char **items, int index, char *item)
{
	items[index] = (char*)malloc(sizeof(*items) * (ft_strlen(item) + 1));
	if (items[index] == NULL)
		return (NULL);
	ft_strcpy(items[index], item);
	free(item);
	return (items);
}

static char	**alloc(size_t len)
{
	char **arr;

	arr = (char**)malloc(sizeof(arr) * len);
	if (arr == NULL)
		return (NULL);
	arr[len - 1] = 0;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		index;
	int		b;
	char	**items;

	if (s == NULL || ft_isascii(c) == 0)
		return (NULL);
	items = alloc(countitems(s, c) + 1);
	i = 0;
	b = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c && b == 0)
		{
			items = append(items, index, getitem((s + i), c));
			index++;
			b = 1;
		}
		if (b == 1 && s[i] == c)
			b = 0;
		i++;
	}
	return (items);
}
