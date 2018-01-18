/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 22:43:55 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/22 22:44:56 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static void	add_hash(t_hash **head, char *str)
{
	t_hash	*filename;

	if (!(filename = (t_hash*)malloc(sizeof(t_hash))))
		return ;
	filename->name = ft_strdup(str);
	filename->next = NULL;
	if (!(*head))
	{
		(*head) = filename;
		return ;
	}
	filename->next = (*head);
	(*head) = filename;
}

void		hash_word(char *name, t_con *env)
{
	unsigned long	hash;
	int				c;
	char			*copy;

	copy = name;
	hash = BINARY_MAX;
	while ((c = ft_tolower(*name++)))
		hash = ((hash << 5) + hash) + c;
	hash %= BINARY_MAX;
	add_hash(&(env->hashsearch[hash]), copy);
}

int			get_hash(char *name)
{
	unsigned long	hash;
	int				c;

	hash = BINARY_MAX;
	while ((c = ft_tolower(*name++)))
		hash = ((hash << 5) + hash) + c;
	hash %= BINARY_MAX;
	return (hash);
}

int			is_binary(char *name, t_con *env)
{
	int		hash;
	t_hash	*temp;
	char	*copy;

	copy = name;
	hash = get_hash(copy);
	if (!(temp = env->hashsearch[hash]))
		return (FALSE);
	while (temp)
	{
		if (!ft_strcmp(name, temp->name))
			return (TRUE);
		temp = temp->next;
	}
	return (FALSE);
}
