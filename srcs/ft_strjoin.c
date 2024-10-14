/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:14:32 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/14 17:38:58 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
    char *out;
    unsigned int i;
    unsigned int j;

    if (!s1 || !s2)
        return (NULL);
    out = ft_calloc(ft_strlen(s1) + ft_strlen(s2), sizeof(char));
    if (!out)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[j])
        out[i++] = s1[j++];
    j = 0;
    while (s2[j])
        out[i++] = s2[j++];
    return (out);
}

// #include <stdio.h>

// int main(void)
// {
//     const char  *s1 = "This sentence is too long ";
//     const char  *s2 = "too fit in one stringg.";
//     const char  *s3;
//     char        *str;

//     str = ft_strjoin(s1, s2);
//     printf("%s\n", str);

//     str = ft_strjoin(s3, s3);
//     printf("%s", str);
//     free(str);
// }