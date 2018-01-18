/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:45:12 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/11 13:39:07 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_split(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	count_words(char const *str)
{
	int	i;
	int	bul;
	int count;

	i = 0;
	bul = 0;
	count = 0;
	while (str[i])
	{
		if (bul == 0 && !is_split(str[i]))
		{
			count++;
			bul = 1;
		}
		if (bul == 1 && is_split(str[i]))
			bul = 0;
		i++;
	}
	return (count);
}

static char	*get_word(char const *str)
{
	int		i;
	int		x;
	char	*ret;

	x = 0;
	while (str[x] && !is_split(str[x]))
		x++;
	if (!(ret = ft_strnew(x)))
		return (NULL);
	x = 0;
	i = 0;
	while (str[x] && !is_split(str[x]))
	{
		ret[i] = str[x];
		x++;
		i++;
	}
	return (ret);
}

char		**ft_strsplit_2(char const *str)
{
	int		i;
	int		x;
	int		bul;
	char	**ret;

	x = count_words(str);
	if (!(ret = ft_listnew(x)))
		return (NULL);
	i = 0;
	x = 0;
	bul = 0;
	while (str[i])
	{
		if (bul == 0 && !is_split(str[i]))
		{
			ret[x] = get_word(&str[i]);
			x++;
			bul = 1;
		}
		if (bul == 1 && is_split(str[i]))
			bul = 0;
		i++;
	}
	return (ret);
}
