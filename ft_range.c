/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:17:21 by bordenoy          #+#    #+#             */
/*   Updated: 2019/03/01 16:21:26 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ascii(t_ls *b)
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
				if (ft_strcmp(b[i].path, b[i + 1].path) > 0)
				{
					gg = b[i];
					b[i] = b[i + 1];
					b[i + 1] = gg;
				}
			i++;
		}
		g--;
	}
}

void ft_rev(t_ls *b)
{
	size_t i;
	size_t g;
	t_ls gg;

	i = 0;
	g = 0;
	while (b[i].pos)
		i++;
	while (g < (i / 2))
	{
		gg = b[g];
		b[g++] = b[i];
		b[i--] = gg;
	}
}
