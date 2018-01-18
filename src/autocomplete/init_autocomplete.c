/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_autocomplete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:16:30 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/01 10:10:32 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char				get_tri_index(int ch)
{
	int index;

	index = (ft_tolower(ch) - 'a');
	if (index >= 0 && index <= 25)
		return (index);
	if (index == -65)
		return (26);
	else if (index == -51)
		return (27);
	else if (index == -60)
		return (28);
	else if (index == -52)
		return (29);
	else if (index == -2)
		return (30);
	else if (index >= -49 && index <= -40)
		return (31 + (index + 49));
	else
		return (-1);
}

static void			initialize_array(t_tri **head)
{
	t_tri	*search;
	int		i;

	search = (*head);
	i = -1;
	while (++i < 42)
	{
		search->letter[i] = NULL;
		search->isword = 0;
	}
}

static char			add_word(char *word, t_tri **head)
{
	int			i;
	int			index;
	t_tri		*search;
	t_tri		*temp;

	i = -1;
	if (!ft_isalpha(word[0]))
		return (FALSE);
	search = (*head);
	while (word[++i])
	{
		if ((index = get_tri_index(word[i])) == -1)
			return (FALSE);
		if (!search->letter[index])
		{
			if (!(temp = (t_tri*)malloc(sizeof(t_tri))))
				return (FALSE);
			initialize_array(&temp);
			search->letter[index] = temp;
			search = search->letter[index];
		}
		else
			search = search->letter[index];
	}
	return ((search->isword = 1));
}

static void			add_indexes(char *dir, t_tri **head, t_con *con)
{
	struct dirent		*pdirent;
	DIR					*pdir;

	if (!(pdir = opendir(dir)))
		return ;
	while ((pdirent = readdir(pdir)))
	{
		if (add_word(pdirent->d_name, head))
			hash_word(pdirent->d_name, con);
	}
	closedir(pdir);
}

void				init_autocomplete(t_con *con)
{
	char	**path;
	char	*env;
	int		i;
	t_tri	*head;

	path = NULL;
	i = -1;
	if (!(head = (t_tri*)malloc(sizeof(t_tri))))
		return ;
	if (!(env = getenv("PATH")))
		return ;
	if (!(path = ft_strsplit(env + 5, ':')))
		return ;
	initialize_array(&head);
	i = -1;
	while (++i < BINARY_MAX)
		con->hashsearch[i] = NULL;
	i = -1;
	con->trisearch = head;
	while (path[++i])
		add_indexes(path[i], &(con->trisearch), con);
	ft_free2dsafe((void***)&path);
}
