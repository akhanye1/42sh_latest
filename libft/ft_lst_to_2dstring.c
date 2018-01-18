/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_2dstring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 15:38:27 by nmbotho           #+#    #+#             */
/*   Updated: 2017/07/29 15:38:40 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	*ft_lst_to_2dstring(t_list **list)
{
	t_list		*next;
	t_string	*str_words;
	t_list		*current;
	int			i;
	int			size;

	i = 0;
	size = ft_lst_count(*list);
	current = *list;
	str_words = (t_string*)malloc(sizeof(t_string*) * (size + 1));
	if (str_words)
	{
		while (current)
		{
			str_words[i] = ft_strdup((const char*)current->content);
			next = current->next;
			current = next;
			i++;
		}
		str_words[i] = NULL;
	}
	ft_lstdel(list, ft_del);
	return (str_words);
}
