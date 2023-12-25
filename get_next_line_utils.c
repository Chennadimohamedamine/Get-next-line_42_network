/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:41 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/25 06:04:46 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_s(char *s ,int f)
{
	int	i;

	i = 0;
	if(f == 1){
		while (s && s[i])
    	{
      		if(s[i] == '\n')
        		return ++i;
        	i++;
    	}
		return (i);
	}
	while (s && s[i])
		i++;
	return (i);
}

int    search(char *s)
{
    int    i;

    i = 0;
    while (s[i])
    {
      if(s[i] == '\n')
        return ++i;
        i++;
    }
    return (i);
}

int	check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char *freemery(char *f1,char *f2){
	if(f1 != NULL)
		free(f1);
	if(f2 != NULL)
		free(f2);
	return NULL;
}
char	*ft_strdup(char *s)
{
	char	*str;
	int		i;
	if(s == NULL)
		return 0;
	str = (char *)malloc(count_s(s,2) + 1);
	if(!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	if(str[0] == 0 && s != NULL){
			free(str);
			return 	NULL;
	}
	return (str);
}

char	*join_line(char *s1, char *s2)
{
	char	*l;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if(!s2)
		return (ft_strdup(s1));
	l = (char *)malloc(count_s(s1,2) + count_s(s2,2) + 2);
	if(!l)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		l[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		l[i++] = s2[j++];
	l[i] = 0;
	free(s1);
	return (l);
}

