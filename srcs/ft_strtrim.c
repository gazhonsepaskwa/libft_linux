/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:42:56 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:53:36 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_instr(int c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
static int	ft_gettrimstart(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (ft_instr(str[i], (char *)set))
		i++;
	return (i);
}
static int	ft_gettrimend(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (ft_instr(str[ft_strlen(str) - i - 1], (char *)set))
		i++;
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*cpy;
	size_t	trimstart;
	size_t	trimend;
	size_t	i;

	cpy = (char *)s1;
	trimstart = ft_gettrimstart(s1, set);
	trimend = ft_gettrimend(s1, set);
	cpy = ft_calloc(ft_strlen(s1) - (trimstart + trimend) + 1, sizeof(char));
	i = 0;
	while (i < ft_strlen(s1) - (trimstart + trimend))
	{
		cpy[i] = s1[trimstart + i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

// #include <stdio.h>
// int main(void)
// {
//  printf("debug: real start");
//     char trimset[100] = "sed";
//     char str[100] = "dseeeOutputsdd";
//     printf("Output ?= %s", ft_strtrim(str, trimset));
//     /// should be freed but how ??
// }