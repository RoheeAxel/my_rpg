/*
** EPITECH PROJECT, 2021
** is upper
** File description:
** func
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    unsigned int str_len = my_strlen(str);
    unsigned int count = 0;

    if (str_len == 0)
        return 1;
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            count++;
    }
    if (count == str_len)
        return 1;
    return 0;
}
