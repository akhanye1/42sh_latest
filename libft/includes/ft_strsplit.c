/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 02:03:43 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/30 15:00:39 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		wrds;

	i = -1;
	wrds = 1;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				wrds++;
		}
	}
	return (wrds);
}

static char	*return_word(char const *s, char c, int *ind)
{
	int			i;
	char		temp[ft_strlen(s) + 1];

	if (s == NULL)
		return (NULL);
	if (s[0] == '\0' || s[0] == c)
		return (NULL);
	ft_bzero(temp, ft_strlen(s) + 1);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	if (s[i] == '\0')
		*ind += i - 1;
	else
		*ind += i;
	return (ft_strdup(temp));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**buffer;
	int		wrds;
	int		i;
	char	*tmp;
	int		cnt;

	if (s == NULL && ft_strlen(s) == 0)
		return (NULL);
	i = -1;
	cnt = 0;
	wrds = count_words(s, c);
	if (wrds == 0)
		return (NULL);
	if (!(buffer = (char**)malloc(sizeof(char*) * (wrds + 1))))
		return (NULL);
	while (s[++i] != '\0')
	{
		tmp = return_word(s + i, c, &i);
		if (tmp != NULL)
			buffer[cnt++] = tmp;
	}
	buffer[cnt] = NULL;
	return (buffer);
}
