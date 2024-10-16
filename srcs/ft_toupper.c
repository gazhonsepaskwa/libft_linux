/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:01:30 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/16 09:09:13 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int main(void)
// {
//     for (int i = 'a'; i <= 'z'; i++)
//     {
//         int result = ft_toupper(i);
//         int expected = toupper(i);
//         printf("ft_toupper('%c') = '%c', expected = '%c' -> %s\n",
//             i, result, expected, (result == expected) ? "PASS" : "FAIL");
//     }

//     for (int i = 'A'; i <= 'Z'; i++)
//     {
//         int result = ft_toupper(i);
//         int expected = toupper(i);
//         printf("ft_toupper('%c') = '%c', expected = '%c' -> %s\n",
//             i, result, expected, (result == expected) ? "PASS" : "FAIL");
//     }

//     int test_chars[] = {'1', '!', ' ', '\n', 'Z', 'm', '@'};
//     int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
//     for (int i = 0; i < num_tests; i++)
//     {
//         int result = ft_toupper(test_chars[i]);
//         int expected = toupper(test_chars[i]);
//         printf("ft_toupper('%c') = '%c', expected = '%c' -> %s\n",
//             test_chars[i], result, expected,
//	(result == expected) ? "PASS" : "FAIL");
//     }
//     return (0);
// }