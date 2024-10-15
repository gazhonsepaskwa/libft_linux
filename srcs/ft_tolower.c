/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:07:21 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:54:02 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
//     for (int i = 'a'; i <= 'z'; i++)
//     {
//         int result = ft_tolower(i);
//         int expected = tolower(i);
//         printf("ft_tolower('%c') = '%c', expected = '%c' -> %s\n",
//             i, result, expected, (result == expected) ? "PASS" : "FAIL");
//     }

//     for (int i = 'A'; i <= 'Z'; i++)
//     {
//         int result = ft_tolower(i);
//         int expected = tolower(i);
//         printf("ft_tolower('%c') = '%c', expected = '%c' -> %s\n",
//             i, result, expected, (result == expected) ? "PASS" : "FAIL");
//     }

//     int test_chars[] = {'1', '!', ' ', '\n', 'Z', 'm', '@'};
//     int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
//     for (int i = 0; i < num_tests; i++)
//     {
//         int result = ft_tolower(test_chars[i]);
//         int expected = tolower(test_chars[i]);
//         printf("ft_tolower('%c') = '%c', expected = '%c' -> %s\n",
//             test_chars[i], result, expected,
//	(result == expected) ? "PASS" : "FAIL");
//     }
//     return (0);
// }