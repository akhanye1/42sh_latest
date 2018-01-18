/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:24:06 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/30 14:52:08 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strtrim(const char *str)
{
	int		b;
	int		e;
	char	*tmp;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) == 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		tmp[0] = '\0';
		return (tmp);
	}
	b = ft_skipempty(str);
	e = ft_lastal(str) + 1;
	if (!(tmp = (char *)malloc(sizeof(char) * ((e - b) + 1))))
		return (NULL);
	if (e == 1 && ft_strlen(str) != 1)
	{
		tmp[0] = '\0';
		return (tmp);
	}
	ft_strcpysub(tmp, str, b, ((e - b)));
	tmp[(e - b)] = '\0';
	return (tmp);
}
