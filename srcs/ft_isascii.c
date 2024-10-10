/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:11:09 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/10 16:45:07 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 255)
		return (1);
	else
		return (0);
}

// tests

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
//      char c = -1;
//      long int d = 2523452423461;
//      int e = 2;
//      char f = 'C';
//      int g = 256;

//      printf("%d\n", ft_isascii(c));
//      printf("%d\n", ft_isascii(d));
//      printf("%d\n", ft_isascii(e));
//      printf("%d\n", ft_isascii(f));
//      printf("%d\n\n", ft_isascii(g));

//      printf("%d\n", isascii(c));
//      printf("%d\n", isascii(d));
//      printf("%d\n", isascii(e));
//      printf("%d\n", isascii(f));
//      printf("%d\n", isascii(g));
// }