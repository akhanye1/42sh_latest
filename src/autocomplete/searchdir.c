/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 13:22:16 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/01 16:23:09 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void				get_filename(t_sfiles *searchhelp, char *filename)
{
	if (filename[0] == '/' && ft_strlen(filename) > 1)
		searchhelp->filename = ft_strdup(filename + 1);
	else if (ft_strlen(filename) && filename[0] != '/')
		searchhelp->filename = ft_strdup(filename);
	else
		searchhelp->filename = ft_strdup("");
}

DIR					*get_directory(t_sfiles *searchhelp, char *folder)
{
	DIR				*pdir;

	if (ft_strrpos(folder, '/') != -1)
		searchhelp->folder = ft_strsub(folder, 0, ft_strrpos(folder, '/'));
	else
		searchhelp->folder = ft_strdup(folder);
	if ((pdir = opendir(folder)))
	{
		free(searchhelp->folder);
		searchhelp->folder = ft_strdup(folder);
		return (pdir);
	}
	if ((pdir = opendir(searchhelp->folder)))
		return (pdir);
	return (NULL);
}
