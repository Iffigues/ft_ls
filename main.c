/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:45:02 by bordenoy          #+#    #+#             */
/*   Updated: 2019/03/01 13:48:09 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	argv++;
	argc--;
	while (argv[i])
		if (ft_strlen(argv[i++]) == 0)
			return (0);
	ft_ls(argc, argv);
	return (0);
}
