/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:37:47 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/28 22:22:34 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void ft_putchar(char c)
{
	 write(1, &c ,1);
}

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

size_t ft_strlen(const char *b)
{
	size_t r;

	r = 0;
	while(*b)
	{
		r++;
		b++;
	}
	return (r);
}
