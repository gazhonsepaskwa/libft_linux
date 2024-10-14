/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:42:56 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/14 18:27:48 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_instr(int c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
    }
    return (0);
}

char    *ft_strtrim(const char *s1, const char *set)
{
    // some code lol
}
