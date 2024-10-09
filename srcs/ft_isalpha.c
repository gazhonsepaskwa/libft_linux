/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:23:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/09 18:02:58 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* NAME
    ft_isalpha -- 42 alphabetic character test

DESCRIPTION
     The ft_isalpha() function tests for any character for which isupper(3) or
     islower(3) is true.  The value of the argument must be representable as
     an unsigned char or the value of EOF.

     In the ASCII character set, this includes the following characters (pre-
     ceded by their numeric values, in octal):

     101 ``A''     102 ``B''     103 ``C''     104 ``D''     105 ``E''
     106 ``F''     107 ``G''     110 ``H''     111 ``I''     112 ``J''
     113 ``K''     114 ``L''     115 ``M''     116 ``N''     117 ``O''
     120 ``P''     121 ``Q''     122 ``R''     123 ``S''     124 ``T''
     125 ``U''     126 ``V''     127 ``W''     130 ``X''     131 ``Y''
     132 ``Z''     141 ``a''     142 ``b''     143 ``c''     144 ``d''
     145 ``e''     146 ``f''     147 ``g''     150 ``h''     151 ``i''
     152 ``j''     153 ``k''     154 ``l''     155 ``m''     156 ``n''
     157 ``o''     160 ``p''     161 ``q''     162 ``r''     163 ``s''
     164 ``t''     165 ``u''     166 ``v''     167 ``w''     170 ``x''
     171 ``y''     172 ``z''

RETURN VALUES
     The isalpha() function returns zero if the character tests false and
     returns non-zero if the character tests true.
*/

int ft_isalpha(int c)
{
     if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
          return (1);
     else
          return (0);
}

// tests

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
//      char c = 'a';
//      int d = 60;
//      int e = 94;
//      char f = 'C';
//      int g = 256;

//      printf("%d\n", ft_isalpha(c));
//      printf("%d\n", ft_isalpha(d));
//      printf("%d\n", ft_isalpha(e));
//      printf("%d\n", ft_isalpha(f));
//      printf("%d\n\n", ft_isalpha(g));

//      printf("%d\n", isalpha(c));
//      printf("%d\n", isalpha(d));
//      printf("%d\n", isalpha(e));
//      printf("%d\n", isalpha(f));
//      printf("%d\n", isalpha(g));
// }