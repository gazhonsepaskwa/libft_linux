/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:17:16 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/14 17:33:38 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;

    if ((size_t)start + len > ft_strlen(s))
        sub = ft_calloc(ft_strlen(s) - (size_t)start, sizeof(char));
    else
        sub = ft_calloc(len, sizeof(char));
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len && s[start + i] != 0)
    {
        sub[i] = s[start + i];
        i++;
    }
    return(sub);
}


// #include <stdio.h>

// int main(void)
// {
//     const char *s = "Eat, sleep, think. But don't die";
//     printf("%s\n", ft_substr(s, 5, 6));                              // HOW TO FREE ????
//     printf("%s", ft_substr(s, 5, 70));                               // HOW TO FREE ????
// }