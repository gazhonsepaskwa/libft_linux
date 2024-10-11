/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:06:54 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/11 09:17:20 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;
    size_t i;

    ptr = (unsigned char *)b;
    i = 0;
    while (i < len)
    {
        ptr[i] = c;
        i++;
    }
    return b;
}

// #include <stdio.h>
// #include <string.h>

// void	printArray(int arr[], int n)
// {
// 	for (int i = 0; i < n; i++)
// 		printf("%d ", arr[i]/16843009);
//     printf("\n\n");
// }

// int main()
// {
//     int n = 10;
// 	int arr[n];
//     int arr2[n];

// 	// int test
// 	ft_memset(arr, 3, n * sizeof(int));
// 	printf("Array after ft_memset()\n");
// 	printArray(arr, n);
//     memset(arr2, 3, n * sizeof(int));
// 	printf("Array after memset()\n");
// 	printArray(arr2, n);

//     // char test
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
//     char str2[50] = "GeeksForGeeks is for programming geeks.";
// 	printf("\nBefore : %s\n", str);

// 	// Fill 8 characters starting from str[13] with '.'
// 	ft_memset(str + 13, '.', 8*sizeof(char));
// 	printf("After ft_memset(): %s \n", str);
//     memset(str2 + 13, '.', 8*sizeof(char));
// 	printf("After    memset(): %s \n", str2);
// 	return 0;
// }

// I have discovered the magic number 16843009 by experimentations.
// It's the decimal interpretetion of writing in a single bit in a
// memory block and interpret the result as 32bit integer (reading
// the whole memory block). I do think at least, some part may be
// incorrect or not enough precise.
