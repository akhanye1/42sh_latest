/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchfiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 09:59:35 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/01 16:22:57 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void				iterate_dir(DIR *pdir, t_sfiles *searchhelp,
								t_con *con, char **trimmed)
{
	int				len;
	int				n;
	struct dirent	*pdirent;

	len = ft_strlen(searchhelp->filename);
	n = -1;
	while ((pdirent = readdir(pdir)) && n < 40)
	{
		if (len == 0)
		{
			if (ft_strcmp(pdirent->d_name, ".") &&
				ft_strcmp(pdirent->d_name, ".."))
				suggestions(pdirent->d_name, ADD, con, &n);
		}
		else if (!ft_strncmp(pdirent->d_name, searchhelp->filename, len))
			suggestions(pdirent->d_name, ADD, con, &n);
	}
	closedir(pdir);
	free(searchhelp->filename);
	free(searchhelp->folder);
	free(trimmed);
	suggestions(NULL, PRINT, con, &n);
}

static void			search_folder(char *folder, char *filename,
		t_con *con, char **trimmed)
{
	DIR				*pdir;
	t_sfiles		searchhelp;

	if (!folder || !ft_strlen(folder) || !filename)
		return ;
	if (!(pdir = get_directory(&searchhelp, folder)))
		return ;
	get_filename(&searchhelp, filename);
	iterate_dir(pdir, &searchhelp, con, trimmed);
}

static int			search_specific_file(char *trim,
		t_con *con, char **trimmed)
{
	if (ft_strchr(trim, '/'))
		search_folder(trim, ft_strrchr(trim, '/'), con, trimmed);
	else
		search_folder(getenv("PWD"), trim, con, trimmed);
	return (TRUE);
}

static int			smart_search(char *trim, t_con *con)
{
	char	**trimmed;
	int		i;

	if (!(trimmed = ft_strsplit(trim, ' ')))
		return (FALSE);
	i = -1;
	while (trimmed[++i])
		;
	if (((i -= 2) >= 0) && (is_binary(trimmed[i], con) ||
				trimmed[i][0] == '-'))
		return (search_specific_file(trimmed[++i], con, trimmed));
	return (FALSE);
}

int					search_files(char *trim, t_con *con)
{
	if (ft_strchr(trim, ' '))
		return (smart_search(trim, con));
	return (TRUE);
}
