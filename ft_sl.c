/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:51:02 by bordenoy          #+#    #+#             */
/*   Updated: 2019/03/01 17:26:32 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void get_dir(DIR *rep, t_ls *ar)
{
	size_t c;
	struct  dirent *lecture;

	c = 0;
	while ((lecture = readdir(rep)))
	{
		ar[c] = ft_make_one(ft_strdup(lecture->d_name), (c + 1));
		c++;
	}
	ar[c] = ft_make_one(NULL, 0);
	closedir(rep);
}

t_ls *ft_make_lr(char *b)
{
	struct stat filestat;
	t_ls *ar;

	ar = (t_ls *)malloc(sizeof(t_ls) * (ft_count_me(b) + 1));
	if ((stat(b, &filestat) < 0) || S_ISREG(filestat.st_mode))
	{
		ar[0] = ft_make_one(b,1);
		ar[1] = ft_make_one(NULL,0);
		return (ar);
	}
	if (S_ISDIR(filestat.st_mode))
		get_dir(opendir(b), ar);
	return (ar);
}

t_ls *ft_take(char *b)
{
	t_ls *ar;

	if (b == NULL)
		ar = ft_make_lr(".");
	else
		ar = ft_make_lr(b);
	return (ar);
}
void ft_begin(t_ls *ar, t_opt opt)
{
	int i;

	if (opt.opt)
		;
	i = 0;
	while (ar[i].pos)
		i++;
	i = 0;
	while (ar[i].pos)
	{
		if (S_ISDIR(ar[i].filestat.st_mode))
		{
			//ab = (t_ls *)malloc(sizeof(t_ls) * (ft_count_ls(ar[i]) + 1));
		}
		i++;
	}
	free(ar);
}

void ft_ls(int ac, char **av)
{
	t_ls *ar;
	t_opt al;
	int i;

	if ((i = parse_option(*av, &al)) < 0)
		return ;
	if (i > 0)
		ac-- && av++;
	if (ac == 0 || ac == 1)
		ar = ft_take(*av);
	else
		ar = ft_male(ac, av);
	ft_range(ar, al);
	ft_brise(ar, al, ac > 1);
}
