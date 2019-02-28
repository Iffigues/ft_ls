/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:45:07 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/28 22:22:57 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <dirent.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <stdio.h>
typedef struct		s_opt
{
	unsigned int 	opt : 5;
}					t_opt;


typedef	struct		s_ls
{
	size_t				pos;
	unsigned int	opt : 5;
	char			*name;
	char			*path;
	DIR				*rep;
	struct	stat 	filestat;
	struct 	dirent	*read; 
}					t_ls;

size_t  ft_getsize(t_ls *b);
int ft_strcmp(char *s1, char *s2);
t_ls ft_make_one(char *b, size_t i);
void    ft_range(t_ls *b);
size_t ft_count_me(char *b);
size_t ft_count_file(DIR *rep);
int parse_option(char *opt, t_opt *opts);
void ft_ls(int ac, char **av);
void ft_putchar(char c);
void ft_putstr(char *s);
size_t ft_strlen(const char *b);
char *ft_strdup(const char *s1);
void    *ft_memalloc(size_t size);
void    *ft_memset(void *b, int c, size_t len);
#endif
