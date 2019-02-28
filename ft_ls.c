/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:44:08 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/28 21:50:50 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_error(char *c)
{
	if (c)
		;
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1  && *s2 && !(*s1 > *s2 || *s1 < *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	parse_option(char *opt, t_opt *opts)
{
	int i;

	i = 0;
	opts->opt = 0;
	if (opt && !(*opt))
		i = 0;
	if (opt && *opt && *opt == '-' && opt++)
	{
		if (*opt == '-')
		{
			if (opt++ && *opt)
				return (-1);
			return (1);
		}
		opts->opt = 4;
		i = 1;
	}
	return (0);
}

size_t ft_getsize(t_ls *b)
{
	size_t c;

	c = 0;
	while (b->pos)
	{
		c = b->pos;
		b++;
	}
	return (c / 2);
}

size_t ft_count(t_ls *ar)
{
	size_t i;

	i = 0;
	while (ar[i].pos)
		i++;
	return (0);
}
