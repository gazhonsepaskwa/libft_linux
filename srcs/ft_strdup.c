/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:38:09 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/14 17:19:34 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_strdup(const char *s1)
{
    char *out;
    unsigned long int i;

    if (!s1)
        return (NULL);
    out = ft_calloc(ft_strlen(s1), sizeof(char));
    if (!out)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        out[i] = s1[i];
        i++;
    }
    out[i] = '\0';
    return (out);
}

// #include <stdio.h>

// int main(void)
// {
//     const char *src = "test";
//     char *dup = ft_strdup(src);

//     printf("src : %s|\ndst : %s|\n", src, dup);
//     free(dup);
// }