/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:24 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/28 03:22:46 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_newline(char *s ,int *r)
{
	char	*str;
	int i;
	
	if(!s)
		return NULL;
	i = 0;
	str = (char *)malloc(count_s(s,1)+ 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		if(s[i] == '\n'){
			str[i++] = '\n';
			break;
		}
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	if(s[i] != '\0')
		*r = i;
	return (str);
}
char *ft_rest_line(char **s, char *s1, int *g)
{
    char *str;
    char *temp;
    int r;

	r = 0;
	str = NULL;
    if (check(*s)) {
		temp = NULL;
        str = get_line_newline(*s, &r);
		if(r != 0)
        	temp = strdup((*s) + r);
        *s = NULL;
        temp = join_line(temp, s1);
		if(!temp)
			return str;
		free(*s);
        *s = strdup(temp);
        *g = 1;
        free(temp);
        return str;
    }
    str = strdup(*s);
	*s = NULL;
    return str;
}
char *ft_get_line(char **s, char *s1)
{
    char *line;
    char *restline;
    char *temp;
    int r;
    
	r = 0;
    restline = NULL;
    if (*s != NULL)
        restline = ft_rest_line(s, s1, &r);
    if (r  == 1)
        return restline;
    temp = get_line_newline(s1, &r);
	if(!temp)
		return restline;
    if (r > 0){
        s1 += r;
        *s = strdup(s1);
    }
    line = join_line(restline, temp);
    freemery(NULL,temp);
    return line;
}

char	*read_line(int fd)
{
	char	*buffer;
	int		r;
	char	*str;

	str = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if(!str)
		return (NULL);
	r = 1;
	buffer = NULL;
	while (r > 0)
	{
		r = read(fd,str, BUFFER_SIZE);
		if (r < 0)
			return (freemery(str,buffer));
		str[r] = '\0';
		buffer = join_line(buffer,str);
		if(!buffer)
		 	return (freemery(str,buffer));
        if(check(buffer) || r == 0 )
          break;
	}
	if(buffer[0] == 0){
		return freemery(str,buffer);
	}
	return (free(str),buffer);
}
char	*get_next_line(int fd)
{
	static char	*s;
	char		*str;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0 || read(fd,s,0) < 0)
		return (NULL);
	line = NULL;
	str = read_line(fd);
	if(!str && !s)
		return (NULL);
	line = ft_get_line(&s, str);
	free(str);
	return (line);
}

// int main(){
// 	int fd = open("files/multiple_nlx5",O_RDONLY);
// 	char *line;
// 	for(int i = 0; i < 11;i++){
// 		line = get_next_line(fd);
// 		printf("all [%d] : %s \n",i+1,line);
// 		printf("\n================== [%d] =================\n",i+1);
// 		free(line);
// 	}

// 	return 0;
// }