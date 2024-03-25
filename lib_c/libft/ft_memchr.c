/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:30:10 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 12:24:29 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		if (*((unsigned char *)s + k) == (unsigned char)c)
			return ((void *)s + k);
		k++;
	}
	return (NULL);
}
/* Retruns the first occurance of the caracter of the value c*/
/* NULL if does not exist */
