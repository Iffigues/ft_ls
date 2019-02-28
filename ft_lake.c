/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lake.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:47:45 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/28 21:41:17 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

void	ft_range(t_ls *b)
{
	size_t i;
	size_t g;
	t_ls gg;

	g = ft_getsize(b);
	while (g)
	{
		i = 0;
		while (b[i].pos)
		{
			if (b[i + 1].pos)
				if (ft_strcmp(b[i].name, b[i + 1].name) > 0)
				{
					ft_putstr(b[i].name);
					ft_putstr(b[i + 1].name);
					gg = b[i];
					b[i] = b[i + 1];
					b[i + 1] = gg;
				}
			i++;
		}
		g--;
	}
}

t_ls ft_make_one(char *b, size_t i)
{
	t_ls ar;

	ar.pos = i;
	ar.name = b;
	if (b && *b)
	{
		ar.path = b;
		stat(b, &ar.filestat);
		if (S_ISDIR(ar.filestat.st_mode))
			ar.rep = opendir(b);
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
	size_t i;
	struct stat filestat;

	stat(b, &filestat);
	if (S_ISDIR(filestat.st_mode))
		i = ft_count_file(opendir(b));
	if (S_ISREG(filestat.st_mode))
		i = 1;
	return (i);
}
