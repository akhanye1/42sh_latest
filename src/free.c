#include "h_42sh.h"

static void free_history(t_history **head)
{
	t_history   *iter;
	t_history   *fr;

	iter = *head;
	while (iter)
	{   
		fr = iter;
		iter = iter->prev;
		free(fr->name);
		free(fr);
	}   
}

static void free_trisearch(t_tri **head)
{
	t_tri   *iter;
	t_tri   *fr;
	int     i;

	iter = *head;
	i = 0;
	while (i < 42)
	{
		if (iter->letter[i])
		{
			fr = iter->letter[i];
			free_trisearch(&iter->letter[i]);
			free(fr);
		}
		i++;
	}
}

static void free_hashsearch(t_hash *hash[BINARY_MAX])
{
	int     i;
	t_hash  *fr;
	t_hash  *temp;

	i = 0;
	while (i < BINARY_MAX)
	{
		if (hash[i])
		{
			temp = hash[i];
			while (temp)
			{
				fr = temp;
				temp = temp->next;
				ft_strdel(&fr->name);
				free(fr);
			}
		}
		i++;
	}
}

void    free_all(t_con *con)
{
	static t_con *memory = NULL;

	if (con)
	{
		memory = con;
		return ;
	}
	if (!memory)
		return ;
	if (memory->clipboard)
		ft_strdel(&memory->clipboard);
	if (memory->history)
		free_history(&memory->history);
	if (memory->trisearch)
		free_trisearch(&memory->trisearch);
	if (memory->temp)
		ft_strdel(&memory->temp);
	free_hashsearch(memory->hashsearch);
	free(memory);
}
