/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:45:20 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:53:31 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack || !needle || needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

// test

// #include <stdio.h>
// #include <string.h>
// int main(int ac, char **av)
// {
//     char *res1;
//     char *res2;
//     size_t n = 50;

//     if (ac == 3 && av[1] != NULL && av[2] != NULL)
//     {
//         res1 = ft_strnstr((const char *)av[1], (const char *)av[2], n);
//         res2 =    strnstr((const char *)av[1], (const char *)av[2], n);

//         if (res1 == res2) printf("test ok\n%s == %s\n", res1, res2);
//         else
//         {
//             printf("error\n\n");
//             printf("ft_strnstr : %s\n", res1);
//             printf("   strnstr : %s\n", res2);
//         }

//         return (0);
//     }
//     else
//     {
//         printf("Test usage: %s <haystack> <needle>\n", av[0]);
//         return (1);
//     }
// }