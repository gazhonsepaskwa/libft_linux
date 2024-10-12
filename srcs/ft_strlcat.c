/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:07:49 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/12 12:11:23 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);

	if (dstsize <= dst_len)
		return (dstsize + src_len);

	i = 0;
	while (src[i] && (dst_len + i) < (dstsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';

	return (dstsize + src_len - 1);
}


#include <stdio.h>
#include <string.h>

// int main(void)
// {
// 	const char	*src = "coucou";
// 	char 		dst[14] = "tralala";
// 	char 		dst2[14] = "tralala";
// 	char 		dst3[14] = "tralala";
// 	size_t		r;

// 	r  = ft_strlcat(dst, src, 0);
// 	printf("After ft_strlcat : %s | return : %zu\n", dst, r);
// 	r =    strlcat(dst, src, 0);
// 	printf("After    strlcat : %s | return : %zu\n\n", dst, r);

// 	r  = ft_strlcat(dst2, src, 5);
// 	printf("After ft_strlcat : %s | return : %zu\n", dst2, r);
// 	r =    strlcat(dst2, src, 5);
// 	printf("After    strlcat : %s | return : %zu\n\n", dst2, r);

// 	r  = ft_strlcat(dst3, src, -12);
// 	printf("After ft_strlcat : %s | return : %zu\n", dst3, r);
// 	// // r =    strlcat(dst3, src, -12);
// 	// // printf("After    strlcat : %s | return (: %zu\n", dst3, r); // overflow warning
// }