/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:02:18 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/10 16:45:10 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// tests

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
//      char c = '0';
//      int d = 4900;
//      int e = 40;
//      char f = '9';
//      int g = 59;

//      printf("%d\n", ft_isdigit(c));
//      printf("%d\n", ft_isdigit(d));
//      printf("%d\n", ft_isdigit(e));
//      printf("%d\n", ft_isdigit(f));
//      printf("%d\n\n", ft_isdigit(g));

//      printf("%d\n", isdigit(c));
//      printf("%d\n", isdigit(d));
//      printf("%d\n", isdigit(e));
//      printf("%d\n", isdigit(f));
//      printf("%d\n", isdigit(g));
// }
