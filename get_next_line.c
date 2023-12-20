/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:24 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/20 06:01:57 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_newline(char *v, char *s)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if(!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if(s[i] == '\n'){
			str[i++] = '\n';
			break;
		}
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	j = 0;
	while (s[i])
		v[j++] = s[i++];
	v[j] = '\0';
	return (str);
}

// char *get_line_newline(char *v, char *s, int r) {
//     char *str;
//     int i, j;

//     str = (char *)malloc(r + 1); // Allocate memory for the entire string
//     i = 0;
//     while (s[i] && s[i] != '\n') {
//         str[i] = s[i];
//         i++;
//     }
//     if (s[i] == '\n') {
//         str[i++] = '\n';
//     }
//     str[i] = '\0'; 
//     j = 0;
//     while (i < r)
//         v[j++] = s[i++];
//     v[j] = '\0'; 
//     return str;
// }
static char	*get_line(char *v, char *l, char *s)
{
	char *newline;
	char *line;
	if(v[0] != 0 && !l){
		l = get_line_newline(v,v);
	}
	if(check(s))
	{
		newline = get_line_newline(v,s);
		line = join_line(l,newline);
		return (free(newline),line);
	}
	else
		line = join_line(l,s);
	return (line);
}

static char	*read_line(char *v, int fd)
{
	char	*line;
	char	*str;
	int		r;

	str = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if(!str)
		return (NULL);
	r = 1;
	line = NULL;
	while (r > 0)
	{
		r = read(fd,str, BUFFER_SIZE);
		if (r < 0)
		{
			v[0] = 0;
		 	return (free(str),free(line), NULL);	
		}
		str[r] = '\0';
		line = get_line(v, line, str);
		if(check(str) || r == 0)
			break;
	}
	if(line[0] == 0)
		return (free(str),free(line),NULL);
	return (free(str), line);
}

char	*get_next_line(int fd)
{
	static char	v_s[BUFFER_SIZE];
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	line = read_line(v_s, fd);
	if(!line)
		return (NULL);
	return (line);
}
