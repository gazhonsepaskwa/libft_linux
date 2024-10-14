/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:35 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/14 11:53:00 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const char *ps = (const char *) s;

    i = 0;
    while (ps[i] != 0 && i < n)
    {
        if (ps[i] == c)
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
//     char    *res  = ft_memchr(str, c, 4);
//     char    *res2 =    memchr(str, c, 4);

//     printf("ft_strchr : %s\n   strchr : %s\n\n", res, res2);
// }