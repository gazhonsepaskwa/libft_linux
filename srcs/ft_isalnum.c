/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:12:06 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:52:50 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	else
		return (0);
}
// the function return 8 for a true on linux...

// tests

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
//     char c = 'a';
//     int d = 60;
//     int e = 94;
//     char f = 'C';
//     int g = 256;
//     char h = '0';
//     int j = 4900;
//     int k = 40;
//     char l = '9';
//     int m = 59;

//     printf("%d\n", ft_isalnum(c));
//     printf("%d\n", ft_isalnum(d));
//     printf("%d\n", ft_isalnum(e));
//     printf("%d\n", ft_isalnum(f));
//     printf("%d\n\n", ft_isalnum(g));

//     printf("%d\n", isalnum(c));
//     printf("%d\n", isalnum(d));
//     printf("%d\n", isalnum(e));
//     printf("%d\n", isalnum(f));
//     printf("%d\n\n", isalnum(g));

//     printf("%d\n", ft_isalnum(h));
//     printf("%d\n", ft_isalnum(j));
//     printf("%d\n", ft_isalnum(k));
//     printf("%d\n", ft_isalnum(l));
//     printf("%d\n\n", ft_isalnum(m));

//     printf("%d\n", isalnum(h));
//     printf("%d\n", isalnum(j));
//     printf("%d\n", isalnum(k));
//     printf("%d\n", isalnum(l));
//     printf("%d\n", isalnum(m));
// }
