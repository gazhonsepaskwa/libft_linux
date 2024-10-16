/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:25:28 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/16 15:58:44 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "includes/libft.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void cprintf(const char *color, const char *format, ...) {
    // Define ANSI color codes
    const char *RED = "\033[31m";
    const char *GREEN = "\033[32m";
    const char *YELLOW = "\033[33m";
    const char *BLUE = "\033[34m";
    const char *MAGENTA = "\033[35m";
    const char *CYAN = "\033[36m";
    const char *WHITE = "\033[37m";
    const char *RESET = "\033[0m";

    // Determine which color to use
    const char *colorCode = RESET;
    if (strcmp(color, "RED") == 0) {
        colorCode = RED;
    } else if (strcmp(color, "GREEN") == 0) {
        colorCode = GREEN;
    } else if (strcmp(color, "YELLOW") == 0) {
        colorCode = YELLOW;
    } else if (strcmp(color, "BLUE") == 0) {
        colorCode = BLUE;
    } else if (strcmp(color, "MAGENTA") == 0) {
        colorCode = MAGENTA;
    } else if (strcmp(color, "CYAN") == 0) {
        colorCode = CYAN;
    } else if (strcmp(color, "WHITE") == 0) {
        colorCode = WHITE;
    }

    // Print the colored text using variadic arguments
    printf("%s", colorCode);  // Set the color

    va_list args;
    va_start(args, format);
    vprintf(format, args);   // Use vprintf to print the formatted string
    va_end(args);

    printf("%s", RESET);     // Reset the color
}

int main(void)
{
    printf("atoi : ");

    char *str[20];
    int lenstr = 10;

    str[0] = "12";
    str[1] = "-4";
    str[2] = "   -4";
    str[3] = "asdjfg";
    str[4] = "aaa67ss";
    str[5] = "126fff";
    str[6] = "as-1";
    str[7] = "--4";
    str[8] = "+4";
    str[9] = "-4a";

    for (int i = 0; i < lenstr; i++)
    {
        if (!(ft_atoi(str[i]) == atoi(str[i])))
        {
            printf("ft_atoi: %d\n   atoi: %d\n\n",
                    ft_atoi(str[i]),atoi(str[i]));
        }
        else
            cprintf("GREEN","OK ");
    }
    printf("\n");

    return (0);
}