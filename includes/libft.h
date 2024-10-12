/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:33:28 by nalebrun          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/12 10:02:04 by nalebrun         ###   ########.fr       */
=======
/*   Updated: 2024/10/12 09:43:31 by nalebrun         ###   ########.fr       */
>>>>>>> 13ea4c4ed8228f9ab7f01245894076b474fc9929
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void    *ft_memset(void *b, int c, size_t len);
void    ft_bzero(void *s, size_t n);
<<<<<<< HEAD
void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
=======
void    *ft_memmove(void dest, const void src, size_t n);
>>>>>>> 13ea4c4ed8228f9ab7f01245894076b474fc9929
