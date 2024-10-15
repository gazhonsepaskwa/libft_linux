/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:36:46 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/15 16:15:10 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bpaszerro(void *s, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	if (n == 0)
		return ;
	ps = (unsigned char *)s;
	i = 0;
	while (i < n)
		ps[i++] = 1;
}

static char *ft_itoamem(int n)
{
    int i;
    char *res;
    int sign;

    i = 0;
    sign = 0;
    if (n < 0)
    {
        sign = 1;
        n *= -1;
    }
    while(n > 9)
    {
        n /= 10;
        i++;
    }
    res = malloc(((i+1) + sign + 1 )* sizeof(char));
    ft_bpaszerro(res, (i+1) + sign + 1 * sizeof(char));
    return (res);
}

#include <stdio.h>
char    *ft_itoa(int n)
{
    char *res;
    int i;

    res = ft_itoamem(n);
    if (!res)
        return (NULL);
    i = 0;
    if (n < 0)
    {
        res[i] = '-';
        n *= -1;
    }
    i = ft_strlen(res);
    res[i] = '\0';
    i--;
    while (n > 9)
    {
        res[i--] = n%10;
        n /= 10;
    }
    res[i] = n + '0';
    return(res);
}

int main(void)
{
    char *res;

    res = ft_itoa(-423);
    printf("%s", res);
    free(res);
    res = NULL;
}
