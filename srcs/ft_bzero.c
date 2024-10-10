/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:07:05 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/10 16:56:01 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *Ps;
	size_t i;

	if (n == 0)
		return ;
	Ps = (unsigned char *)s;
	i = 0;
	while (i < n)
		Ps[i++] = 0;
}

#include <stdio.h>
int main(void)
{
    char *str = "strrr";
    ft_bzero(str, 3);
    printf("After ft_memset(): %s \n", str);
}
