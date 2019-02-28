/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:25:11 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/28 22:19:00 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*g;

	if (!(str = ft_memalloc(ft_strlen(s1) + 1)))
		return (NULL);
	g = str;
	while (*s1)
		ft_memset(str++, *s1++, 1);
	ft_memset(str, 0, 1);
	return (g);
}
