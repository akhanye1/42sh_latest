/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:18:37 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/10 12:50:06 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char *dest, const char *src)
{
	int		tl;
	char	*tmp;

	if ((src == NULL) || (dest == NULL))
		return (NULL);
	tl = (int)ft_strlen(dest) + (int)ft_strlen(src) + 1;
	tmp = (char *)malloc(tl);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_strcpy(tmp, dest);
	tmp = ft_strcat(tmp, src);
	return (tmp);
}
