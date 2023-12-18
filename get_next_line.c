/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:00:24 by mochenna          #+#    #+#             */
/*   Updated: 2023/12/18 15:33:56 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// char *get_line_newline(char *v,char *s,int r)
// {
//     if(!s)
//         return NULL;
//     char *str =(char *)malloc(search(s) + 1);
//     int  i = 0;
//     int  j;
//     while(s[i] && s[i] == '\n'){
//         str[i] = s[i];
//         i++;
//     }
//     str[i++] = 0;
//     j = 0;
//     while(i <= r && s[j] != 0)
//       v[j++] = s[i++];
//     v[j] = 0;
//     return str;
// }
// char *get_line(char *v,char *l,char *s,int *g)
// {
//     char *temp;
//     char *line;
//     if(v[0] != '\0'){
//           temp = get_line_newline(v,v,BUFFER_SIZE);
//             line  = join_line(temp,s);
//             free(temp);
//     }else if(check(s) && s[0] != 0){
//         *g = 1; 
//         temp = get_line_newline(v,s,BUFFER_SIZE);
//         line  = join_line(l,temp);
//         free(temp);
//     }else
//         line  = join_line(l,s);
//     return line;
// }

// char *get_next_line(int fd)
// {
//     static char v_s[BUFFER_SIZE];
//     char *str= (char *)malloc((size_t)BUFFER_SIZE + 1 );
//     if(BUFFER_SIZE < 0 || fd < 0){
//         free(str);
//         return (NULL);
//     }
        
//     int r = 1;
//     char *line = ft_strdup("");
//     char *temp;
//     int g = 0;
//     while (r > 0) {
//         r = read(fd, str, BUFFER_SIZE);
//         if(str[0] == '\0'){
//             free(str);
//             free(line);
//             return (NULL);
//         }
            
//         str[r] = 0;
//         temp = get_line(v_s,line, str, &g);
//         free(line);
//         line = temp; 
//         if(g == 1)
//             break;
//         }
//     free(str); 
//     return line;
// }
//==================================================

char *get_line_newline(char *v, char *s, int r) {
    if (!s)
        return NULL;
    char *str = (char *)malloc(strlen(s) + 2);
    int i = 0;
    int j;
    while (s[i]){
        str[i] = s[i];
        if(s[i] == '\n')
            break;
        i++;
    }
    str[++i] = '\0';
    j = 0;
    while (i < r && s[i] != 0)
        v[j++] = s[i++];
    v[j] = '\0';
    return str;
}

char *get_line(char *v, char *l, char *s, int *g) {
    char *temp;
    char *line;
    if (v[0] != '\0') {
        temp = get_line_newline(v, v, BUFFER_SIZE);
        line = join_line(temp, s);
        free(temp);
    } else if (check(s) && s[0] != 0) {
        *g = 1;
        temp = get_line_newline(v, s, BUFFER_SIZE);
        line = join_line(l, temp);
        free(temp);
    } else {
        line = join_line(l, s);
    }
    return line;
}

char *get_next_line(int fd) {
    
    if (BUFFER_SIZE < 0 || fd < 0)
        return NULL;
    static char v_s[BUFFER_SIZE];
    char *str = (char *)malloc((size_t)BUFFER_SIZE + 1);

    int r = 1;
    char *line = strdup("");
    char *temp;
    int g = 0;
    while (r > 0) 
    {
        r = read(fd, str, BUFFER_SIZE);
        if (r < 0)
        {
            free(str);
            free(line);
            return NULL;
        }
        str[r] = '\0';
        temp = get_line(v_s, line, str, &g);
        free(line);
        line = temp;
        if (g == 1)
            break;
    }
    free(str);
    if(line[0] =='\0'){
        free(line);
        return NULL;
    }
        
    return line;
}
