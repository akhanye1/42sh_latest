/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:23:33 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/17 14:48:28 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = NULL;
	if (content == NULL)
		content_size = 0;
	lst = (t_list*)malloc(sizeof(t_list) * 1);
	if (lst == NULL)
	{
		content_size = 0;
		return (NULL);
	}
	if (content == NULL)
		lst->content = NULL;
	else
	{
		lst->content = NULL;
		lst->content = ft_memdup((unsigned char*)content, content_size);
	}
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
