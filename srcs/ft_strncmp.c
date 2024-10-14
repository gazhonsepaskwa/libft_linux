/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:58:07 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/14 11:37:07 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

    n = 3;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}


// test

// #include <stdio.h>
// #include <string.h>
// int main(int ac, char **av)
// {
//     int res1;
//     int res2;

//     if (ac == 3 && av[1] != NULL && av[2] != NULL)
//     {
//         res1 = ft_strncmp((const char *)av[1], (const char *)av[2], 10);
//         res2 =    strncmp((const char *)av[1], (const char *)av[2], 10);

//         if (res1 == res2) printf("test ok\n%d == %d\n", res1, res2);
//         else
//         {
//             printf("error\n\n");
//             printf("ft_strncmp : %d\n", res1);
//             printf("   strncmp : %d\n", res2);
//         }

//         return (0);
//     }
//     else
//     {
//         printf("Test usage: %s <string1> <string2>\n", av[0]);
//         return (1);
//     }
// }
