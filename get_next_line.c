/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:24 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/19 04:43:11 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_newline(char *v, char *s, int r)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(search(s) + 2);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		if (s[i] == '\n')
			break ;
		i++;
	}
	str[++i] = '\0';
	j = 0;
	while (i < r)
		v[j++] = s[i++];
	v[j] = '\0';
	return (str);
}

char	*get_line(char *v, char *l, char *s, int *g)
{
	char	*temp;
	char	*line;

	if (v[0] != '\0')
	{
		temp = get_line_newline(v, v, BUFFER_SIZE);
		line = join_line(temp, s);
		free(temp);
	}
	else if (check(s))
	{
		*g = 1;
		temp = get_line_newline(v, s, BUFFER_SIZE);
		line = join_line(l, temp);
		free(temp);
	}
	else
		line = join_line(l, s);
	 if (line[0] == '\0')
	 	return (free(line), NULL);
	return (line);
}

char	*read_line(char *v_s, int fd)
{
	char	*str;
	char	*line;
	char	*temp;
	int		r;
	int		g;

	str = (char *)malloc((size_t)BUFFER_SIZE + 1);
	r = 1;
	line = strdup("");
	g = 0;
	while (r > 0 && g != 1)
	{
		r = read(fd, str, BUFFER_SIZE);
		if (r < 0)
			return (free(str), free(line), NULL);
		str[r] = '\0';
		temp = get_line(v_s, line, str, &g);
		free(line);
		line = temp;
	}
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
