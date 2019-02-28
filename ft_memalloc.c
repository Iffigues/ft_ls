/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:05:08 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/28 22:19:42 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memalloc(size_t size)
{
	void	*o;

	if (!(o = (void *)malloc(size)))
		return ((void *)0);
	return (ft_memset(o, 0, size));
}
