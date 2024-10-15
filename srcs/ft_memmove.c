/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:37:46 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:52:21 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	if (pdst < psrc)
	{
		while (n--)
			*pdst++ = *psrc++;
	}
	else
	{
		pdst += n;
		psrc += n;
		while (n--)
			*(--pdst) = *(--psrc);
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str1[50] = "Hello, World!";
//     char str2[50] = "Goodbye, World!";

//     ft_memmove(str1 + 7, str1, 6);
//     printf("ft_memmove result: %s\n", str1);

//     ft_memmove(str2, str2 + 8, 6);
//     printf("ft_memmove result: %s\n", str2);

// 	memmove(str1 + 7, str1, 6);
//     printf("memmove result: %s\n", str1);

//     memmove(str2, str2 + 8, 6);
//     printf("memmove result: %s\n", str2);

//     return (0);
// }
