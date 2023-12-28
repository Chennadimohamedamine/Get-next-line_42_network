/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 03:24:43 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/28 01:57:30 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:54 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/19 03:24:15 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <libc.h>
# include <fcntl.h>

int		search(char *s);
char	*ft_strdup(char *s);
int		check(char *s);
int		count_s(char *s,int f);
char	*join_line(char *s1, char *s2);
char	*get_next_line(int fd);
char *freemery(char *f1,char *f2);
#endif
