/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:01:43 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:53:23 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

// test

// #include <stdio.h>
// #include <string.h>

// int main()
// {

//     size_t len = ft_strlen(NULL);
//     printf("Length of the string: %zu\n", len);

//     size_t len2 = ft_strlen("Coucou");
//     printf("Length of the string: %zu\n", len2);

//     return (0);
// }