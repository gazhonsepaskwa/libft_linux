/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:06:01 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/14 10:57:21 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s);
    while (i != 0)
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i--;
    }
    return (NULL);
}


// #include <stdio.h>
// #include <string.h>

// int main (void)
// {
//     char    *str = "tralala";
//     char    c = 'l';
//     char    *res = ft_strrchr(str, c);
//     char    *res2 = ft_strrchr(str, c);

//     printf("ft_strchr : %s\n   strchr : %s\n\n", res, res2);
// }