/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:01:48 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/08 14:36:56 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinpath(char const *s1, char const *s2)
{
	char	*ret;
	char	*tmp;
	size_t	l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = (ft_strlen(s1) + ft_strlen(s2));
	tmp = ft_strnew(ft_strlen(s1) + 1);
	ft_strcat(tmp, s1);
	tmp[ft_strlen(s1)] = '/';
	ret = ft_strnew(l + 1);
	ft_strcat(ret, tmp);
	ft_strcat(ret, s2);
	free(tmp);
	return (ret);
}
