/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:00:41 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:52:56 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res *= sign);
}

// tests

// #include <stdlib.h>
// #include <stdio.h>

// int main(void)
// {
//     char *str[20];
//     int error = 0;
//     int lenstr = 10;

//     str[0] = "12";
//     str[1] = "-4";
//     str[2] = "   -4";
//     str[3] = "asdjfg";
//     str[4] = "aaa67ss";
//     str[5] = "126fff";
//     str[6] = "as-1";
//     str[7] = "--4";
//     str[8] = "+4";
//     str[9] = "-4a";

//     for (int i = 0; i < lenstr; i++)
//     {
//         if (!(ft_atoi(str[i]) == atoi(str[i]))) // ft_atoi(str[i])
//         {
//             printf("ft_atoi: %d\n   atoi: %d\n\n",
//                     ft_atoi(str[i]),atoi(str[i]));
//             error = 1;
//         }
//     }
//     if (error == 0)
//         printf("Tests OK\n");

//     return (0);
// }
