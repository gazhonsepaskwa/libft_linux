/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:37:46 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/12 09:55:28 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *pdst;
    unsigned char *psrc;
    unsigned char tmp[500000];
    size_t i;

    pdst = (unsigned char *)dst;
    psrc = (unsigned char *)src;
    i = 0;
    while (i < n)
    {
        pdst[i] = psrc[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        pdst[i] = tmp[i];
        i++;
    }
    return (dst);
}