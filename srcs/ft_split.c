/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:28:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/16 10:09:28 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *s, int start, int end)
{
	int		i;
	char	*word;

	word = ft_calloc(end - start + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	if (s[end + 1] == 0)
		end++;
	while (start < end)
		word[i++] = s[start++];
	word[i] = 0;
	return (word);
}

char	**truc(int word_count, const char *s, char c)
{
	int		start;
	int		end;
	int		i;
	char	**result;

	start = -1;
	end = -1;
	i = 0;
	result = ft_calloc((word_count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (s[++end])
	{
		if (s[end] != c && start == -1)
			start = end;
		if ((s[end] == c || s[end + 1] == '\0') && start != -1)
		{
			result[i++] = copy_word(s, start, end);
			start = -1;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = truc(count_words(s, c), s, c);
	if (!result)
		return (NULL);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str = "Hello, this is a splited string";
// 	char		**result;

// 	result = ft_split(str, ' ');
// 	for (int i = 0; result[i] != NULL; i++)
// 	{
// 		printf("{%s} ", result[i]);
// 		free(result[i]);
// 	}
// 	free(result);
// 	result = NULL;
// 	return (0);
// }
