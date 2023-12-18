/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:41 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/18 01:20:01 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int count_s(char *s){
    int i = 0;
    while(s[i])
        i++;
    return i;
}
int search(char *s){
    int i = 0;
    while(s[i] != '\n' && s[i]){
        i++;
    }
    return i;
}
int check(char *s){
    int i = 0;
    while(s[i]){
        if(s[i] == '\n')
           return  1;
        i++;
    }
    return 0;
}
char *ft_strdup(char *s)
{
    if(s == NULL)
        return NULL;
    char *str = (char *)malloc(count_s(s) + 1);
    int i = 0;
    while(s[i]){
        str[i] = s[i];
        i++;
    }
    str[i] = 0;
    return str;
}
char *join_line(char *s1 ,char *s2)
{
    if(!s1){
        return (ft_strdup(s2));
    }
    char *l=(char *)malloc(count_s(s1) + count_s(s2) + 1);
    
        
    int i = 0;
    int j;
    while(s1[i]){
        l[i] = s1[i];
        i++;
    }
    j = 0;
    while(s2[j]){
        l[i] = s2[j];
        j++;
        i++;
    }
    l[i] = 0;
    return l;
}