/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:23:47 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/12 10:10:22 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// tests

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// 		char c = '`';
// 		int d = 4900;
// 		int e = 127;
// 		char f = '~';
// 		int g = 31;
// 		int h = '	';
// 		int i = ' ';

// 		printf("%d\n", ft_isprint(c));
// 		printf("%d\n", ft_isprint(d));
// 		printf("%d\n", ft_isprint(e));
// 		printf("%d\n", ft_isprint(f));
// 		printf("%d\n", ft_isprint(g));
// 		printf("%d\n", ft_isprint(h));
// 		printf("%d\n\n", ft_isprint(i));

// 		printf("%d\n", isprint(c));
// 		printf("%d\n", isprint(d));
// 		printf("%d\n", isprint(e));
// 		printf("%d\n", isprint(f));
// 		printf("%d\n", isprint(g));
// 		printf("%d\n", isprint(h));
// 		printf("%d\n\n", isprint(i));
// }