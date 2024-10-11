/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:07:05 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/11 09:20:42 by nalebrun         ###   ########.fr       */
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
		Ps[i++] = 3;
}

// #include <stdio.h>
// #include <string.h>
// void	printArray(int arr[], int n)
// {
// 	for (int i = 0; i < n; i++)
// 		printf("%d ", arr[i]/16843009);
//     printf("\n\n");
// }
// int main(void)
// {
//     char str[6] = "strrr";
// 	int n = 2;
//     int arr[6] = {0,1,2,3,4,5};

// 	printf("str testes : \n");
//     ft_bzero(str, n);
//     printf("After ft_bzero(): %s \n", str);
// 	ft_bzero(str, n);
//     printf("After bzero(): %s \n", str);

// 	printf("\nint testes : \n");
//     ft_bzero(arr, n);
//     printf("After ft_bzero():\n");
// 	printArray(arr, 6);
// 	ft_bzero(arr, n);
//     printf("After bzero():\n");
// 	printArray(arr, 6);

// }
