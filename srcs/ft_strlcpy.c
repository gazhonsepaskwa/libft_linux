/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:07:49 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:53:20 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && i < ft_strlen(src))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	const char	*src = "coucou";
// 	size_t		n = 7;
// 	char 		dst[n];
// 	size_t		r;

// 	ft_bzero(dst, n);

// 	r  = ft_strlcpy(dst, src, 0);
// 	printf("After ft_strlcpy : %s | return (: %zu\n", dst, r));
// 	r =    strlcpy(dst, src, 0);
// 	printf("After    strlcpy : %s | return (: %zu\n\n", dst, r));

// 	r  = ft_strlcpy(dst, src, 4);
// 	printf("After ft_strlcpy : %s | return (: %zu\n", dst, r));
// 	r =    strlcpy(dst, src, 4);
// 	printf("After    strlcpy : %s | return (: %zu\n\n", dst, r));

// 	r =    strlcpy(dst, src, -12);
// 	printf("After    strlcpy : %s | return (: %zu\n", dst, r));
// 	r  = ft_strlcpy(dst, src, -12);
// 	printf("After ft_strlcpy : %s | return (: %zu\n", dst, r));
// }