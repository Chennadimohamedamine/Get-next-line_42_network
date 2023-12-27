/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:24 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/27 09:12:35 by mochenna         ###   ########.fr       */
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
    if (check(*s)) {
        str = get_line_newline(*s, &r);
        temp = strdup((*s) + r);
        *s = NULL;
        temp = join_line(temp, s1);
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
	temp = NULL;
    if (*s != NULL)
        restline = ft_rest_line(s, s1, &r);
    if (r  == 1)
        return restline;
    temp = get_line_newline(s1, &r);
	if(!temp && *s != NULL)
		*s = NULL;
    if (r > 0) {
        s1 += r;
        *s = strdup(s1);
    }
    line = join_line(restline, temp);
    if (line[0] == 0 || !line){
        return freemery(restline, temp);
	}
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
	static char	*v_s;
	char		*str;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0 || read(fd,v_s,0) < 0)
		return (NULL);
	line = NULL;
	str = read_line(fd);
	if(!str && !v_s)
		return (NULL);
	line = ft_get_line(&v_s, str);
	if(!line){
		return(freemery(str,line));
	}
	free(str);
	return (line);
}

int main(){
	int fd = open("files/alternate_line_nl_with_nl",O_RDONLY);
	char *line;
	for(int i = 0; i < 10;i++){
		line = get_next_line(fd);
		printf("\n================== [%d] =================\n",i+1);
		printf("all [%d] : %s \n",i+1,line);
		free(line);
	}

	return 0;
}