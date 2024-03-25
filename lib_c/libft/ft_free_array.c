/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:43:54 by yparthen          #+#    #+#             */
/*   Updated: 2024/02/18 14:55:48 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_free_array(void **s, int size_s, void (ft_free)(void *))
{
    int k;

    k = 0;
    if (s)
    {
        while (k < size_s)
        {
            ft_free(s[k]);
            k++;
        }
        ft_free(s);
    }
}

void ft_free(void *data)
{
    if (data)
        free(data);
}

/*  This function frees a array pointers    */
