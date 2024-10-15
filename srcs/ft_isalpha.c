/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:23:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:52:47 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	else
		return (0);
}

// tests

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
//      char c = 'a';
//      int d = 60;
//      int e = 94;
//      char f = 'C';
//      int g = 256;

//      printf("%d\n", ft_isalpha(c));
//      printf("%d\n", ft_isalpha(d));
//      printf("%d\n", ft_isalpha(e));
//      printf("%d\n", ft_isalpha(f));
//      printf("%d\n\n", ft_isalpha(g));

//      printf("%d\n", isalpha(c));
//      printf("%d\n", isalpha(d));
//      printf("%d\n", isalpha(e));
//      printf("%d\n", isalpha(f));
//      printf("%d\n", isalpha(g));
// }
