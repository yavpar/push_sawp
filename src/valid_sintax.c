/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sintax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:39:06 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/19 22:59:18 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  This function checks the syntax of the arguments:	*/
/*  Valid characters: "-+0123456789"					*/
/*  INTEGER types: INT_MIN <= nbr <= INT_MAX			*/
/*  Unique numbers										*/
static int is_int(char *s);
static int check_doubles(char **s, int size_data);
static int valid_chars(char *s);

int valid_sintax(char **s, int size_data)
{
    int k;

    k = 0;
    while (k < size_data)
    {
        if (!valid_chars(s[k]) || !is_int(s[k]) ||
            !check_doubles(s, size_data))
            return (0);
        k++;
    }
    return (1);
}

static int check_doubles(char **s, int size_data)
{
    int k;
    int j;
    k = 0;
    while (k < size_data - 1)
    {
        j = k + 1;
        while (j < size_data)
        {
            if (s[j] == NULL || s[k] == NULL)
                return (0);
            if (ft_atoi(s[j]) == ft_atoi(s[k]))
                return (0);
            j++;
        }
        k++;
    }
    return (1);
}

static int valid_chars(char *s)
{
    if (!s)
        return (0);
    while (*s >= 9 && *s <= 13)
        s++;
    if (*s == '-' || *s == '+')
    {
        s++;
        if (*s == '\0')
            return (0);
    }
    while (*s)
    {
        if (!ft_isdigit(*s))
            return (0);
        s++;
    }
    return (1);
}

static int is_int(char *s)
{
    long n;

    if (ft_strlen(s) > 11)
        return (0);
    n = ft_atol(s);
    if (n < INT_MIN || n > INT_MAX)
        return (0);
    return (1);
}

