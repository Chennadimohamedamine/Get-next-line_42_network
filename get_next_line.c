/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:24 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/25 06:03:45 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_newline(char **v ,char *s)
{
	char	*str;
	int i;
	
	i = 0;
	str = (char *)malloc(count_s(s,1)+ 1);
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
	s += i;
	if(s!= NULL)
		*v = ft_strdup(s);
	if(count_s(*v,2) == 0){
		free(*v);
	}
	return  (str);
}
static char	*ft_get_line(char **s,char *s1)
{
    char *newline = NULL;
    char *line = NULL;
	char *buffer;
    int g = 0;
    if (*s != NULL) {
      	if(check(*s))
    		g = 1;
      		newline = get_line_newline(&(*s), *s);
    	}
		if(g == 1 ){ 
			 *s = join_line(*s,s1);
		return newline;
      }
	if(s1 != NULL)
    	line = get_line_newline(&(*s), s1);
	buffer = join_line(newline, line);
	if(buffer[0] == 0)
		return (freemery(NULL,buffer));
	
	// if(newline != NULL)
	// 	free(newline);
    return (free(line),buffer);
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
	
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	line = NULL;
	str = read_line(fd);
	if(!str && !v_s)
		return (NULL);
		
	line = ft_get_line(&v_s, str);
	if(!line){
		if(v_s!= NULL)
			free(v_s);
		return(freemery(str,line));
	}
	free(str);
	return (line);
}
// int main()
// {
// 	int fd = open("file5.txt",O_RDONLY);
// 	char *line;
// 	for(int i = 0; i < 7;i++){
// 		line = get_next_line(fd);
// 		printf("all [%d] : N \n",i);
// 		printf("\n================== [%d] =================\n",i);
// 		free(line);
// 	}
// 	return 0;
// }
