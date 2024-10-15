/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:21:39 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:52:24 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;
	size_t				i;

	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char src[] = "Hello, World!";
//     char dst[20];
//     char dst2[20];

//     ft_memcpy(dst, src, 13);
//     memcpy(dst2, src, 13);
//     printf("ft_memcpy result: %s\n", dst);
//     printf("memcpy    result: %s\n", dst2);

//     return (0);
// }
