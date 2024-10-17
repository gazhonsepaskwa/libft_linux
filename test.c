/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:25:28 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/17 19:08:29 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "includes/libft.h"
#include <bsd/string.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

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
    printf("\nFirst part :\n");
    printf("\natoi    : ");

    char *str[15];
    int lenstr = 15;

    str[0] = "0";
    str[1] = "-0";
    str[2] = "2147483647";   // INT_MAX
    str[3] = "-2147483648";  // INT_MIN
    str[4] = "   42";
    str[5] = "   -42";
    str[6] = "   +42";
    str[7] = "-+42";         // Invalid input
    str[8] = "42abc";        // Invalid input, should stop at 42
    str[9] = "abc42";        // Invalid input, should return 0
    str[10] = "--42";        // Invalid input
    str[11] = " + 42";       // Invalid input, should return 0
    str[12] = "000123";      // Should return 123
    str[13] = "   -000123";  // Should return -123
    str[14] = "2147483648";  // Overflow, larger than INT_MAX

    int i = 0;
    while (i < lenstr)
    {
        int original = atoi(str[i]);
        int custom = ft_atoi(str[i]);

        if (original != custom)
        {
            cprintf("RED", "\nft_atoi: %d\n   atoi: %d\n\n", custom, original);
            return 1;
        }
        else
            cprintf("GREEN","OK ");
        i++;
    }

    printf("\n");

    printf("bzero   : ");

    char buffer1[20];
    char buffer2[20];

    char buf1_small[5];
    char buf2_small[5];

    char buf1_large[100];
    char buf2_large[100];

    // Test 1: Small buffer, set all to zero
    memset(buf1_small, 'A', 5);
    memset(buf2_small, 'A', 5);
    ft_bzero(buf1_small, 5);
    bzero(buf2_small, 5);

    if (memcmp(buf1_small, buf2_small, 5) != 0)
    {
        cprintf("RED", "\nMismatch detected in small buffer full zeroing\n");
        return 1;
    }
    else
        cprintf("GREEN", "OK ");

    // Test 2: Partially zero a buffer
    memset(buffer1, 'B', 20);
    memset(buffer2, 'B', 20);
    ft_bzero(buffer1, 10);
    bzero(buffer2, 10);

    if (memcmp(buffer1, buffer2, 20) != 0)
    {
        cprintf("RED", "\nMismatch detected in partial zeroing\n");
        return 1;
    }
    else
        cprintf("GREEN", "OK ");

    // Test 3: Large buffer
    memset(buf1_large, 'C', 100);
    memset(buf2_large, 'C', 100);
    ft_bzero(buf1_large, 50);
    bzero(buf2_large, 50);

    if (memcmp(buf1_large, buf2_large, 100) != 0)
    {
        cprintf("RED", "\nMismatch detected in large buffer zeroing\n");
        return 1;
    }
    else
        cprintf("GREEN", "OK ");

    printf("\n");

//     printf("calloc : ");

//     void *ptr1, *ptr2;
//     void *test1, *test2;
//     void *check1, *check2;
// #include <limits.h>
//     // Test 1: Allocate zero-sized memory
//     ptr1 = ft_calloc(INT_MIN + 3, INT_MIN + 3);
//     ptr2 = calloc(0, 0);

//     if ((ptr1 == NULL && ptr2 != NULL) || (ptr1 != NULL && ptr2 == NULL))
//     {
//         cprintf("RED", "\nMismatch in zero-size allocation\n");
//         return 1;
//     }
//     else
//         cprintf("GREEN", "OK ");

//     free(ptr1);
//     free(ptr2);

//     // Test 2: Small memory block allocation
//     test1 = ft_calloc(5, sizeof(char));
//     test2 = calloc(5, sizeof(char));

//     if (memcmp(test1, test2, 5 * sizeof(char)) != 0)
//     {
//         cprintf("RED", "\nMismatch in small memory block\n");
//         return 1;
//     }
//     else
//         cprintf("GREEN", "OK ");

//     free(test1);
//     free(test2);

//     // Test 3: Allocate and check larger blocks
//     check1 = ft_calloc(100, sizeof(int));
//     check2 = calloc(100, sizeof(int));

//     if (memcmp(check1, check2, 100 * sizeof(int)) != 0)
//     {
//         cprintf("RED", "\nMismatch in large memory block\n");
//         return 1;
//     }
//     else
//         cprintf("GREEN", "OK ");

//     free(check1);
//     free(check2);

//     // Test 4: Edge case - very large allocation
//     size_t large_size = 1000000;
//     void *large1 = ft_calloc(large_size, sizeof(char));
//     void *large2 = calloc(large_size, sizeof(char));

//     if (large1 == NULL || large2 == NULL)
//     {
//         if (large1 != large2)
//         {
//             cprintf("RED", "\nMismatch in handling large allocations\n");
//             return 1;
//         }
//     }
//     else if (memcmp(large1, large2, large_size) != 0)
//     {
//         cprintf("RED", "\nMismatch in large block content\n");
//         return 1;
//     }
//     else
//         cprintf("GREEN", "OK ");

//     free(large1);
//     free(large2);

//     printf("\n");

    printf("isalnum : ");

    int test_chars[] = {
        'a',     // Lowercase alphabetic
        'Z',     // Uppercase alphabetic
        '5',     // Numeric
        '0',     // Numeric
        '9',     // Numeric
        '!',     // Non-alphanumeric
        '@',     // Non-alphanumeric
        ' ',     // Space, non-alphanumeric
        '\t',    // Tab, non-alphanumeric
        127,     // DEL, non-alphanumeric
        -5,      // Non-printable, out of ASCII range
        300      // Non-standard extended ASCII character
    };

    int char_count = 12;
    int index = 0;

    while (index < char_count)
    {
        int libc_result = isalnum(test_chars[index]);
        int custom_result = ft_isalnum(test_chars[index]);

        if (libc_result != custom_result)
        {
            cprintf("RED", "\nMismatch for character '%c' (ASCII: %d)\nft_isalnum: %d\n   isalnum: %d\n\n",
                    test_chars[index], test_chars[index], custom_result, libc_result);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");

        index++;
    }

    printf("\n");

    printf("isalpha : ");

    int check_chars[] = {
        'a',     // Lowercase alphabetic
        'z',     // Lowercase alphabetic
        'A',     // Uppercase alphabetic
        'Z',     // Uppercase alphabetic
        'm',     // Lowercase in the middle of the alphabet
        'M',     // Uppercase in the middle of the alphabet
        '0',     // Numeric, non-alphabetic
        '9',     // Numeric, non-alphabetic
        '-',     // Non-alphabetic special character
        '!',     // Non-alphabetic special character
        ' ',     // Space, non-alphabetic
        '\n',    // Newline, non-alphabetic
        127,     // DEL, non-alphabetic
        -5,      // Non-printable, out of ASCII range
        300      // Non-standard extended ASCII character
    };

    int alpha_count = 15;
    int position = 0;

    while (position < alpha_count)
    {
        int libc_alpha = isalpha(check_chars[position]);
        int custom_alpha = ft_isalpha(check_chars[position]);

        if (libc_alpha != custom_alpha)
        {
            cprintf("RED", "\nMismatch for character '%c' (ASCII: %d)\nft_isalpha: %d\n   isalpha: %d\n\n",
                    check_chars[position], check_chars[position], custom_alpha, libc_alpha);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");

        position++;
    }

    printf("\n");

    printf("isascii : ");

    int ascii_chars[] = {
        0,    // NUL (ASCII 0)
        31,   // Control character (ASCII 31)
        32,   // Space (ASCII 32)
        65,   // 'A' (ASCII 65)
        90,   // 'Z' (ASCII 90)
        97,   // 'a' (ASCII 97)
        122,  // 'z' (ASCII 122)
        127,  // DEL (ASCII 127)
        128,  // Non-ASCII (ASCII 128)
        255,  // Non-ASCII (ASCII 255)
        -1,   // Negative value, out of ASCII range
        300   // Non-standard extended ASCII character
    };

    int ascii_count = 12;
    int index_position = 0;

    while (index_position < ascii_count)
    {
        int libc_ascii = isascii(ascii_chars[index_position]);
        int custom_ascii = ft_isascii(ascii_chars[index_position]);

        if (libc_ascii != custom_ascii)
        {
            cprintf("RED", "\nMismatch for character ASCII value %d\nft_isascii: %d\n   isascii: %d\n\n",
                    ascii_chars[index_position], custom_ascii, libc_ascii);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");

        index_position++;
    }

    printf("\n");

    printf("isdigit : ");

    int digit_chars[] = {
        '0',   // Digit character
        '1',   // Digit character
        '2',   // Digit character
        '3',   // Digit character
        '4',   // Digit character
        '5',   // Digit character
        '6',   // Digit character
        '7',   // Digit character
        '8',   // Digit character
        '9',   // Digit character
        'a',   // Non-digit character
        'Z',   // Non-digit character
        ' ',   // Non-digit character
        '\n',  // Non-digit character
        -1,    // Non-digit, out of range
        256    // Non-digit, out of range
    };

    int digit_count = 15;
    int idx = 0;

    while (idx < digit_count)
    {
        int libc_digit = isdigit(digit_chars[idx]);
        int custom_digit = ft_isdigit(digit_chars[idx]);

        if (libc_digit != custom_digit)
        {
            cprintf("RED", "\nMismatch for character '%c' (ASCII: %d)\nft_isdigit: %d\n   isdigit: %d\n\n",
                    digit_chars[idx], digit_chars[idx], custom_digit, libc_digit);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");

        idx++;
    }

    printf("\n");

    printf("isprint : ");

    int print_chars[] = {
        32,   // Space (ASCII 32)
        33,   // '!' (ASCII 33)
        64,   // '@' (ASCII 64)
        65,   // 'A' (ASCII 65)
        90,   // 'Z' (ASCII 90)
        97,   // 'a' (ASCII 97)
        122,  // 'z' (ASCII 122)
        126,  // '~' (ASCII 126)
        127,  // DEL (ASCII 127, not printable)
        128,  // Non-ASCII (not printable)
        -1,   // Non-printable (out of range)
        10,   // Newline (ASCII 10, not printable)
        12,   // Form feed (ASCII 12, not printable)
        31,   // Control character (ASCII 31, not printable)
        255   // Non-standard extended ASCII (not printable)
    };

    int print_count = 15;
    int pos = 0;

    while (pos < print_count)
    {
        int libc_print = isprint(print_chars[pos]);
        int custom_print = ft_isprint(print_chars[pos]);

        if (libc_print != custom_print)
        {
            cprintf("RED", "\nMismatch for ASCII value %d\nft_isprint: %d\n   isprint: %d\n\n",
                    print_chars[pos], custom_print, libc_print);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");

        pos++;
    }

    printf("\n");

    printf("itoa    : ");

    int test_cases[] = {
        0,          // Zero
        1,          // Positive integer
        -1,         // Negative integer
        123456,     // Positive integer
        -123456,    // Negative integer
        2147483647, // Maximum int value
        -2147483648,// Minimum int value
        42,         // Arbitrary positive integer
        -42,        // Arbitrary negative integer
        99999999    // Large positive integer
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int current_test = 0;

    while (current_test < num_tests)
    {
        char *libc_result = NULL;
        char *custom_result = ft_itoa(test_cases[current_test]);

        libc_result = (char *)malloc(12 * sizeof(char)); // Enough space for all integers
        snprintf(libc_result, 12, "%d", test_cases[current_test]);

        if (strcmp(custom_result, libc_result) != 0)
        {
            cprintf("RED", "\nMismatch for number %d\nft_itoa: %s\n   itoa: %s\n\n",
                    test_cases[current_test], custom_result, libc_result);
            free(libc_result);
            free(custom_result);
            return 1;
        }
        else
        {
            cprintf("GREEN", "OK ");
        }

        free(libc_result);
        free(custom_result);
        current_test++;
    }

    printf("\n");

    printf("memchr  : ");

    char *sample_memory = "Hello, World!";
    int characters_to_test[] = {
        'H',    // First character
        'o',    // Middle character
        'W',    // Capital letter
        '!',    // Special character
        'z',    // Character not in string
        0       // Null terminator
    };

    int num_characters = sizeof(characters_to_test) / sizeof(characters_to_test[0]);
    int current_index = 0;

    while (current_index < num_characters)
    {
        char *libc_result = memchr(sample_memory, characters_to_test[current_index], strlen(sample_memory));
        char *custom_result = ft_memchr(sample_memory, characters_to_test[current_index], strlen(sample_memory));

        if (libc_result != custom_result)
        {
            cprintf("RED", "\nMismatch for character '%c' (ASCII: %d)\nft_memchr: %p\n   memchr: %p\n\n",
                    characters_to_test[current_index], characters_to_test[current_index], (void *)custom_result, (void *)libc_result);
            return 1;
        }
        else
        {
            cprintf("GREEN", "OK ");
        }

        current_index++;
    }

    printf("\n");

    printf("memcmp  : ");
    cprintf("RED", "(segfault)\n");
    // printf("memcmp : ");

    // const char *first_string = "Hello, World!";
    // const char *second_string = "Hello, World!";
    // const char *third_string = "Hello, everyone!";
    // const char *fourth_string = "Hello, World!"; // Same as first_string
    // const char *fifth_string = "Hello, World! Extra text"; // Longer string for comparison

    // struct {
    //     const char *input_one;
    //     const char *input_two;
    //     size_t length;
    //     int expected_outcome;
    // } memcmp_tests[] = {
    //     {first_string, second_string, 13, 0},          // Identical strings
    //     {first_string, third_string, 13, 1},            // Different strings
    //     {first_string, fourth_string, 13, 0},           // Identical strings (same as first_string)
    //     {first_string, fifth_string, 13, 0},            // First part identical
    //     {first_string, fifth_string, 14, -1},           // First part identical, extra character in fifth_string
    //     {second_string, third_string, 10, 0},           // Same first 10 characters
    //     {third_string, second_string, 15, 1},            // Different strings, third_string longer
    // };

    // int total_tests = sizeof(memcmp_tests) / sizeof(memcmp_tests[0]);
    // int current_case_index = 0;

    // while (current_case_index < total_tests)
    // {
    //     int standard_result = memcmp(memcmp_tests[current_case_index].input_one,
    //                                   memcmp_tests[current_case_index].input_two,
    //                                   memcmp_tests[current_case_index].length);
    //     int custom_result = ft_memcmp(memcmp_tests[current_case_index].input_one,
    //                                    memcmp_tests[current_case_index].input_two,
    //                                    memcmp_tests[current_case_index].length);

    //     if (standard_result != custom_result)
    //     {
    //         cprintf("RED", "\nMismatch for case %d\nft_memcmp: %d\n   memcmp: %d\n\n",
    //                 current_case_index, custom_result, standard_result);
    //         return 1;
    //     }
    //     else
    //     {
    //         cprintf("GREEN", "OK ");
    //     }

    //     current_case_index++;
    // }

    // printf("\n");

    printf("memcpy  : ");

    char src_buffer1[] = "Hello, World!";
    char src_buffer2[] = "Goodbye, World!";
    char dest_buffer1[20];
    char dest_buffer2[20];
    char dest_buffer3[20];

    struct {
        char *src;
        char *dest;
        size_t length;
        char *expected_output;
    } memcpy_cases[] = {
        {src_buffer1, dest_buffer1, 13, "Hello, World!"},    // Complete copy
        {src_buffer2, dest_buffer2, 15, "Goodbye, World!"},   // Complete copy
        {src_buffer1, dest_buffer3, 5, "Hello"},              // Partial copy
        {src_buffer1, dest_buffer3, 0, ""},                   // Zero length copy
        {src_buffer1 + 7, dest_buffer1, 6, "World!"},         // Copy part of the source
    };

    int num_cases = sizeof(memcpy_cases) / sizeof(memcpy_cases[0]);
    int cci = 0;

    while (cci < num_cases)
    {
        memset(dest_buffer1, 0, sizeof(dest_buffer1));
        memset(dest_buffer2, 0, sizeof(dest_buffer2));
        memset(dest_buffer3, 0, sizeof(dest_buffer3));

        char *result_ptr = ft_memcpy(memcpy_cases[cci].dest, 
                                      memcpy_cases[cci].src, 
                                      memcpy_cases[cci].length);

        // Use the standard memcpy for expected result
        memcpy(memcpy_cases[cci].dest, memcpy_cases[cci].src, 
               memcpy_cases[cci].length);
        char *expected_ptr = memcpy_cases[cci].expected_output;

        if (strncmp(result_ptr, expected_ptr, memcpy_cases[cci].length) != 0)
        {
            cprintf("RED", "\nMismatch for case %d\nft_memcpy result: %s\nExpected result: %s\n\n",
                    cci, result_ptr, expected_ptr);
            return 1;
        }
        else
        {
            cprintf("GREEN", "OK ");
        }

        cci++;
    }

    printf("\n");

    printf("memmove : ");

    char src1[] = "Hello, World!";
    char src2[] = "Goodbye, World!";
    char buf1[20];
    char buf2[20];
    char buf3[20];

    struct {
        char *s;
        char *d;
        size_t n;
        char *expected;
    } cases[] = {
        {src1, buf1, 13, "Hello, World!"},    // Complete copy
        {src2, buf2, 15, "Goodbye, World!"},   // Complete copy
        {src1, buf3, 5, "Hello"},              // Partial copy
        {src1, buf3, 0, ""},                   // Zero length copy
        {src1 + 7, buf1, 6, "World!"},         // Overlapping regions
    };

    num_cases = 0;
    num_cases = sizeof(cases) / sizeof(cases[0]);
    i = 0;

    while (i < num_cases)
    {
        memset(buf1, 0, sizeof(buf1));
        memset(buf2, 0, sizeof(buf2));
        memset(buf3, 0, sizeof(buf3));

        char *result = ft_memmove(cases[i].d, cases[i].s, cases[i].n);

        // Use the standard memmove for expected result
        memmove(cases[i].d, cases[i].s, cases[i].n);
        char *expected = cases[i].expected;

        if (strncmp(result, expected, cases[i].n) != 0)
        {
            cprintf("RED", "\nMismatch for case %d\nft_memmove result: %s\nExpected result: %s\n\n",
                    i, result, expected);
            return 1;
        }
        else
        {
            cprintf("GREEN", "OK ");
        }

        i++;
    }

    printf("\n");

    printf("memset  : ");
    cprintf("RED", "(error left) ");

    char buffer1x[20];
    char buffer2x[20];
    char buffer3[20];

    struct {
        char *buf;
        int c;
        size_t n;
        char *expected;
    } test_cases2[] = {
        {buffer1x, 'A', 5, "AAAAA"},                // Fill with 'A'
        {buffer2x, 'B', 10, "BBBBBBBBBB"},         // Fill with 'B'
        {buffer3, 'C', 0, ""},                     // Zero length, should be empty
        //{buffer1x, 'D', 15, "DDDDDDDDDDDDDDDDDDD"},   // More than buffer size
    };

    int total_cases = sizeof(test_cases2) / sizeof(test_cases2[0]);
    int index2 = 0;

    while (index2 < total_cases)
    {
        memset(buffer1x, 0, sizeof(buffer1x));
        memset(buffer2x, 0, sizeof(buffer2x));
        memset(buffer3, 0, sizeof(buffer3));

        char *result = ft_memset(test_cases2[index2].buf, test_cases2[index2].c, test_cases2[index2].n);

        // Use the standard memset for expected result
        memset(test_cases2[index2].buf, test_cases2[index2].c, test_cases2[index2].n);
        char *expected = test_cases2[index2].expected;

        if (strncmp(result, expected, strlen(expected)) != 0)
        {
            cprintf("RED", "\nMismatch for case %d\nft_memset result: %s\nExpected result:  %s\n\n",
                    index2, result, expected);
            return 1;
        }
        else
        {
            cprintf("GREEN", "OK ");
        }

        index2++;
    }

    printf("\n");

    printf("strdup  : ");

    struct {
        const char *input;
        const char *expected;
    } test_casess[] = {
        {"Hello, World!", "Hello, World!"},   // Normal string
        {"Goodbye, World!", "Goodbye, World!"}, // Another normal string
        {"", ""},                               // Empty string
        {NULL, NULL},                           // NULL input (check behavior)
    };

    int total_casess = sizeof(test_casess) / sizeof(test_casess[0]);
    index = 0;

    while (index < total_casess)
    {
        char *result = ft_strdup(test_casess[index].input);

        if (test_casess[index].expected == NULL)  // Check for NULL expected result
        {
            if (result != NULL)  // If ft_strdup did not return NULL
            {
                cprintf("RED", "\nMismatch for case %d\nft_strdup result: %s\nExpected: NULL\n\n",
                        index, result);
                free(result); // Free allocated memory before returning
                return 1;
            }
        }
        else
        {
            if (strcmp(result, test_casess[index].expected) != 0)  // Compare strings
            {
                cprintf("RED", "\nMismatch for case %d\nft_strdup result: %s\nExpected: %s\n\n",
                        index, result, test_casess[index].expected);
                free(result); // Free allocated memory before returning
                return 1;
            }
        }

        cprintf("GREEN", "OK ");
        if (result != NULL)  // Free only if result is not NULL
        {
            free(result);
        }
        index++;
    }

    printf("\n");

    printf("strlen  : ");

    const char *test_casesss[7];
    lenstr = 7;

    test_casesss[0] = "Hello, World!";
    test_casesss[1] = "   Leading spaces";
    test_casesss[2] = "";
    test_casesss[3] = "1234567890";
    test_casesss[4] = NULL;
    test_casesss[5] = "A very long string that exceeds usual limits";
    test_casesss[6] = "Spaces   ";

    index = 0;
    while (index < lenstr)
    {
        size_t ft_result = ft_strlen(test_casesss[index]);
        size_t std_result = (test_casesss[index] == NULL) ? 0 : strlen(test_casesss[index]);

        if (ft_result != std_result)
        {
            cprintf("RED", "\nft_strlen: %zu\n   strlen: %zu\n\n", ft_result, std_result);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");
        index++;
    }
    printf("\n");

    printf("strlcpy : ");
    cprintf("RED", "(wtf) \n");
    // printf("strlcpy : ");

    // const char ssrc1[] = "Hello, World!";
    // const char ssrc2[] = "Short";
    // const char ssrc3[] = "";
    // const char ssrc4[] = "A very long string that exceeds buffer size";
    // char sdest1[20];
    // char sdest2[10];
    // char sdest3[20];
    // char sdest4[10];

    // const char *arrr[4][3] = {
    //     {ssrc1, sdest1, "Hello, World!"},
    //     {ssrc2, sdest2, "Short"},
    //     {ssrc3, sdest3, ""},
    //     {ssrc4, sdest4, "A very l"},
    // };

    // size_t sizes[4] = {20, 10, 20, 10};
    // index = 0;

    // while (index < 4)
    // {
    //     size_t ft_result = ft_strlcpy(arrr[index][0], arrr[index][1], sizes[index]);
    //     size_t std_result = strlcpy(arrr[index][0], arrr[index][1], sizes[index]);

    //     if (ft_result != std_result || strcmp(arrr[index][1], arrr[index][2]) != 0)
    //     {
    //         cprintf("RED", "\nMismatch for case %d\nft_strlcpy: %zu, dst: %s\n   strlcpy: %zu, dst: %s\n\n",
    //                 index, ft_result, arrr[index][1], std_result, arrr[index][2]);
    //         return 1;
    //     }
    //     else
    //         cprintf("GREEN", "OK ");
    //     index++;
    // }

    // printf("\n");

    printf("strlcat : ");

    char rdest1[20] = "Hello, ";
    char rdest2[20] = "Short";
    char rdest3[20] = "Initial";
    const char *rsrc1 = "World!";
    const char *rsrc2 = " is a test";
    const char *rsrc3 = "";

    const char *bruh[3][4] = {
        {rdest1, rsrc1, "Hello, World!", "20"}, // Normal case
        {rdest2, rsrc2, "Short is a test", "20"}, // Normal case
        {rdest3, rsrc3, "Initial", "20"}, // Empty source
    };

    size_t rsizes[4] = {20, 20, 20, 20};
     index = 0;

    while (index < 3)
    {
        char buffer1[100];
        char buffer2[100];
        strcpy(buffer1, bruh[index][0]);
        strcpy(buffer2, bruh[index][0]);

        size_t ft_result = ft_strlcat(buffer1, bruh[index][1], rsizes[index]);
        size_t std_result = strlcat(buffer2, bruh[index][1], rsizes[index]);

        if (ft_result != std_result || strcmp(buffer1, bruh[index][2]) != 0)
        {
            cprintf("RED", "\nMismatch for case %d\nft_strlcat: %zu, dst: %s\n   strlcat: %zu, dst: %s\n\n",
                    index, ft_result, buffer1, std_result, buffer2);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");
        index++;
    }

    cprintf("CYAN", "(check src bigger than buffer)\n");

    printf("toupper : ");

    char x[16];

    x[0] = 'a';
    x[8] = 'A';

    x[1] = 'z';
    x[9] = 'Z';

    x[2] = 'A';
    x[10] = 'A';

    x[3] = 'Z';
    x[11] = 'Z';

    x[4] = '1';
    x[12] = '9';

    x[5] = '!';
    x[13] = '~';

    x[6] = ' ';
    x[14] = ' ';

    x[7] = '\0';
    x[15] = '\0';


    int a = 0;

    while (a < 15)
    {
        int b = ft_toupper(x[a]);
        int c = toupper(x[a]);

        if (b != c)
        {
            cprintf("RED", "\nMismatch for case %d\nft_toupper: %d\n   toupper: %d\n\n",
                    a, b, c);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");

        b = ft_tolower(x[a]);
        c = tolower(x[a]);

        a++;
    }

    printf("\ntolower : ");
    a = 0;

    while (a < 15)
    {
        int b = ft_toupper(x[a]);
        int c = toupper(x[a]);

        if (b != c)
        {
            cprintf("RED", "\nMismatch for case %d\nft_tolower: %d\n   tolower: %d\n\n",
                    a, b, c);
            return 1;
        }
        else
            cprintf("GREEN", "OK ");

        b = ft_tolower(x[a]);
        c = tolower(x[a]);

        a++;
    }

    printf("\n");

    printf("strchr  : ");
    cprintf("RED", "(last test crash (giving NULL))");

    // const char *d[8];
    // int t[8];

    // d[0] = "Hello, World!";
    // t[0] = 'W'; // Character is in the string

    // d[1] = "Hello, World!";
    // t[1] = 'H'; // First character in the string

    // d[2] = "Hello, World!";
    // t[2] = '!'; // Last character in the string

    // d[3] = "Hello, World!";
    // t[3] = 'o'; // Character appears more than once, should return first occurrence

    // d[4] = "Hello, World!";
    // t[4] = 'z'; // Character not in the string

    // d[5] = "";
    // t[5] = 'a'; // Empty string, should return NULL

    // d[6] = "Test";
    // t[6] = '\0'; // Null character, should return the null terminator

    // d[7] = NULL;
    // t[7] = 'T'; // NULL string, should handle gracefully

    // int r = 0;

    // while (r < 8)
    // {
    //     const char *u = ft_strchr(d[r], t[r]);
    //     const char *v = strchr(d[r], t[r]);

    //     if (u != v)
    //     {
    //         cprintf("RED", "\nMismatch for case %d\nft_strchr: |%s|\n   strchr: |%s|\n\n",
    //                 r, u ? u : "NULL", v ? v : "NULL");
    //         return 1;
    //     }
    //     else
    //         cprintf("GREEN", "OK ");
    //     r++;
    // }

    printf("\n");

    printf("strrchr : ");
    cprintf("RED","(last test crash (giving NULL))");

    // const char *xj[8];
    // int tb[8];

    // xj[0] = "Hello, World!";
    // tb[0] = 'o'; // Character appears more than once, should return last occurrence

    // xj[1] = "Hello, World!";
    // tb[1] = 'H'; // First character in the string

    // xj[2] = "Hello, World!";
    // tb[2] = '!'; // Last character in the string

    // xj[3] = "Hello, World!";
    // tb[3] = 'W'; // Middle character

    // xj[4] = "Hello, World!";
    // tb[4] = 'z'; // Character not in the string

    // xj[5] = "";
    // tb[5] = 'a'; // Empty string, should return NULL

    // xj[6] = "Test";
    // tb[6] = '\0'; // Null character, should return the null terminator

    // xj[7] = NULL;
    // tb[7] = 'T'; // NULL string, should handle gracefully

    // int rd = 0;

    // while (rd < 8)
    // {

    //     const char *oy = ft_strrchr(xj[rd], tb[rd]);
    //     const char *oy_builtin = strrchr(xj[rd], tb[rd]);

    //     if (oy != oy_builtin)
    //     {
    //         printf("\nMismatch for case %d\n", rd);
    //         cprintf("RED", "ft_strrchr: |%s|\n   strrchr: |%s|\n\n", oy ? oy : "NULL", oy_builtin ? oy_builtin : "NULL");
    //         return 1;
    //     }
    //     else
    //         cprintf("GREEN", "OK ");
    //     rd++;
    // }

    printf("\n");

    printf("strncmp : ");
    cprintf("RED", "(last test crash (giving NULL))");

    // const char *qs1[8];
    // const char *qs2[8];
    // int nd[8];

    // qs1[0] = "Hello, World!";
    // qs2[0] = "Hello, World!";
    // nd[0] = 5; // Identical strings, n < full length

    // qs1[1] = "Hello, World!";
    // qs2[1] = "Hello";
    // nd[1] = 7; // First string longer than the second, should not be identical

    // qs1[2] = "Test";
    // qs2[2] = "Testing";
    // nd[2] = 4; // First `n` characters match, should be identical

    // qs1[3] = "apple";
    // qs2[3] = "apricot";
    // nd[3] = 3; // First `n` characters match, but strings diverge after

    // qs1[4] = "abc";
    // qs2[4] = "ABC";
    // nd[4] = 3; // Case-sensitive comparison, should not be equal

    // qs1[5] = "";
    // qs2[5] = "";
    // nd[5] = 1; // Empty strings, should be identical

    // qs1[6] = "Hello";
    // qs2[6] = "";
    // nd[6] = 0; // Comparing 0 characters, should be considered identical

    // qs1[7] = "Hello";
    // qs2[7] = NULL; // NULL input should be handled gracefully
    // nd[7] = 4;

    // int randomIndex = 0;

    // while (randomIndex < 8)
    // {

    //     int customComparison = ft_strncmp(qs1[randomIndex], qs2[randomIndex], nd[randomIndex]);
    //     int originalComparison = strncmp(qs1[randomIndex], qs2[randomIndex], nd[randomIndex]);

    //     if ((customComparison == 0 && originalComparison != 0) || 
    //         (customComparison != 0 && originalComparison == 0) || 
    //         ((customComparison < 0) != (originalComparison < 0)) || 
    //         ((customComparison > 0) != (originalComparison > 0)))
    //     {
    //         printf("\nMismatch for case %d\n", randomIndex);
    //         cprintf("RED", "ft_strncmp: %d\n   strncmp: %d\n\n", customComparison, originalComparison);
    //         return 1;
    //     }
    //     else
    //         cprintf("GREEN", "OK ");
    //     randomIndex++;
    // }

    printf("\n");

     printf("strnstr : ");
     cprintf("RED", "(last test crash (giving NULL))");

    // const char *ss1[8];
    // const char *ss2[8];
    // size_t lens[8];

    // ss1[0] = "Hello, World!";
    // ss2[0] = "World";
    // lens[0] = 13; // Substring is within bounds

    // ss1[1] = "Hello, World!";
    // ss2[1] = "lo";
    // lens[1] = 5; // Substring occurs within the first part of the string

    // ss1[2] = "Hello, World!";
    // ss2[2] = "o, W";
    // lens[2] = 8; // Substring is a portion within the bounds

    // ss1[3] = "Hello, World!";
    // ss2[3] = "world"; 
    // lens[3] = 13; // Case-sensitive check (should not find)

    // ss1[4] = "Hello, World!";
    // ss2[4] = "!";
    // lens[4] = 10; // Substring is at the end of the string

    // ss1[5] = "Hello, World!";
    // ss2[5] = "z"; 
    // lens[5] = 13; // Substring not found

    // ss1[6] = "Hello, World!";
    // ss2[6] = ""; // Empty substring should return the original string
    // lens[6] = 13;

    // ss1[7] = NULL; // NULL string should handle gracefully
    // ss2[7] = "test";
    // lens[7] = 4;

    // int uniqueIndex = 0;

    // while (uniqueIndex < 8)
    // {
    //     const char *result_custom = ft_strnstr(ss1[uniqueIndex], ss2[uniqueIndex], lens[uniqueIndex]);
    //     const char *result_original = strnstr(ss1[uniqueIndex], ss2[uniqueIndex], lens[uniqueIndex]);

    //     if ((result_custom == NULL && result_original != NULL) || (result_custom != NULL && result_original == NULL) || 
    //         (result_custom && result_original && strcmp(result_custom, result_original) != 0))
    //     {
    //         cprintf("RED", "\nMismatch for case %d\nft_strnstr: |%s|\n   strnstr: |%s|\n\n",
    //                 uniqueIndex, result_custom ? result_custom : "NULL", result_original ? result_original : "NULL");
    //         return 1;
    //     }
    //     else
    //         cprintf("GREEN", "OK ");
    //     uniqueIndex++;
    // }

    printf("\n");

    printf("\nSecond part :\n");

    printf("substr : ");

    const char *input_str[8];
    unsigned int start[8];
    size_t len[8];

    input_str[0] = "Hello, World!";
    start[0] = 7;
    len[0] = 5; // Should return "World"

    input_str[1] = "Hello, World!";
    start[1] = 0;
    len[1] = 5; // Should return "Hello"

    input_str[2] = "Hello, World!";
    start[2] = 0;
    len[2] = 20; // Should return "Hello, World!" (beyond the string length)

    input_str[3] = "Hello, World!";
    start[3] = 15;
    len[3] = 5; // Start index out of bounds, should return ""

    input_str[4] = "Hello, World!";
    start[4] = 7;
    len[4] = 0; // Should return "" (zero length)

    input_str[5] = "";
    start[5] = 0;
    len[5] = 5; // Should return "" (empty string)

    input_str[6] = "Test string";
    start[6] = 5;
    len[6] = 100; // Should return "string" (longer than actual length)

    input_str[7] = NULL; // NULL string should handle gracefully
    start[7] = 0;
    len[7] = 5;

    i = 0;

    while (i < 8) {
        char *result_custom = ft_substr(input_str[i], start[i], len[i]);
        char *result_original = NULL;

        if (input_str[i] != NULL) {
            result_original = (char *)malloc(len[i] + 1); // Allocate memory for the original function
            if (result_original) {
                size_t j = 0;
                if (start[i] < strlen(input_str[i])) {
                    while (j < len[i] && input_str[i][start[i] + j] != '\0') {
                        result_original[j] = input_str[i][start[i] + j];
                        j++;
                    }
                }
                result_original[j] = '\0'; // Null-terminate
            }
        }

        if ((result_custom == NULL && result_original != NULL) || 
            (result_custom != NULL && result_original == NULL) || 
            (result_custom && result_original && strcmp(result_custom, result_original) != 0)) 
        {
            cprintf("RED", "\nMismatch for case %d\nft_substr: |%s|\n   original: |%s|\n\n",
                    i, result_custom ? result_custom : "NULL", result_original ? result_original : "NULL");
            return 1;
        } else {
            cprintf("GREEN", "OK ");
        }

        free(result_custom); // Free allocated memory
        if (result_original) free(result_original); // Free allocated memory

        i++;
    }

    printf("\n");

    printf("strjoin : ");

    const char *str1[6];
    const char *str2[6];

    str1[0] = "Hello, ";
    str2[0] = "World!"; // Expected: "Hello, World!"

    str1[1] = "Good ";
    str2[1] = "Morning!"; // Expected: "Good Morning!"

    str1[2] = "Test";
    str2[2] = NULL; // Expected: NULL

    str1[3] = NULL;
    str2[3] = "String"; // Expected: NULL

    str1[4] = NULL;
    str2[4] = NULL; // Expected: NULL

    str1[5] = "Nothing";
    str2[5] = " to see here."; // Expected: "Nothing to see here."

    i = 0;

    while (i < 6) {
        char *result = ft_strjoin(str1[i], str2[i]);
        char *expected;

        if (str1[i] == NULL || str2[i] == NULL) {
            expected = NULL; // Expected NULL if either input is NULL
        } else {
            expected = (char *)malloc(strlen(str1[i]) + strlen(str2[i]) + 1);
            if (expected) {
                strcpy(expected, str1[i]);
                strcat(expected, str2[i]);
            }
        }

        if ((result == NULL && expected != NULL) || 
            (result != NULL && expected == NULL) || 
            (result && expected && strcmp(result, expected) != 0)) 
        {
            cprintf("RED", "\nMismatch for case %d\nft_strjoin: |%s|\nExpected: |%s|\n\n",
                    i, result ? result : "NULL", expected ? expected : "NULL");
            free(result);
            free(expected);
            return 1;
        } else {
            cprintf("GREEN", "OK ");
        }

        free(result); // Free allocated memory
        if (expected) free(expected); // Free allocated memory if it was allocated

        i++;
    }

    printf("\n");

    return (0);
}