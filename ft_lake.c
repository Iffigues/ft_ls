/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lake.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:47:45 by bordenoy          #+#    #+#             */
/*   Updated: 2019/03/01 19:13:12 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_range(t_ls *b, t_opt opt)
{
	if (!(opt.opt & 1))
		ft_ascii(b);
	if (opt.opt & 2)
		ft_rev(b);
}

t_ls ft_make_one(char *b, size_t i)
{
	t_ls ar;

	ar.pos = i;
	if (b && *b)
	{
		ar.path = ft_strdup(b);
		ar.error = stat(ar.path, &ar.filestat);
		lstat(ar.path, &ar.filelink);
		if (ar.error >= 0)
		{
			if (S_ISDIR(ar.filestat.st_mode))
				ar.rep = opendir(b);
		}
	}
	return (ar);
}

t_ls ft_make_ls(t_ls ar, char *b, int i)
{
	t_ls ab;
	
	if (b && i)
		;
	ab = ar;
	return (ab);
}

size_t ft_count_file(DIR *rep)
{
	struct	dirent *lecture;
	size_t	i;

	i = 0;
	while ((lecture = readdir(rep)))
	{
		i++;
	}
	closedir(rep);
	return (i);
}

size_t ft_count_me(char *b)
{
	struct stat filestat;

	if ((stat(b, &filestat) < 0) || S_ISREG(filestat.st_mode))
		return (1);
	if (S_ISDIR(filestat.st_mode))
		return (ft_count_file(opendir(b)));
	return (0);
}
