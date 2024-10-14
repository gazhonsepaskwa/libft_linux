/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:06:01 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/14 11:52:26 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != 0)
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i ++;
    }
    return (NULL);
}


// #include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     char    *str = "tralala";
//     char    c = 'l';
//     char    *res  = ft_strchr(str, c);
//     char    *res2 =    strchr(str, c);

//     printf("ft_strchr : %s\n   strchr : %s\n\n", res, res2);
// }