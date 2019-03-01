/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_male.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:09:43 by bordenoy          #+#    #+#             */
/*   Updated: 2019/03/01 18:27:37 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int make_opt(char *b)
{
	int i;

	i = 0;
	if (b && *b)
	{
		while (*b)
		{
			b++;
		}
	}
	return (i);
}

t_ls *ft_male(int ac, char **av)
{
	t_ls *ar;
	size_t i;

	i = 0;
	ar = (t_ls *)malloc(sizeof(t_ls) * (ac + 1));
	while (*av)
	{
		ar[i] = ft_make_one(*av++, (i + 1));
		i++;
	}
	ar[i].pos = 0;
	return (ar);
}

void ft_brise(t_ls *ls, t_opt opt, int i)
{
	opt.opt = 0;
	if (!(i))
	{
	}
	else
	{
		i = 0;
		while (ls[i++].pos)
			if (ls[i - 1].error >=0 && S_ISREG(ls[i - 1].filestat.st_mode))
				printf("%s\n",ls[i - 1].path);
		i = 0;
		while (ls[i++].pos)
			if (ls[i -1].error >= 0 && S_ISDIR(ls[i - 1].filestat.st_mode))
				printf("ho is dir\n");
		free(ls);
	}
}
