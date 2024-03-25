/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:25:16 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 12:55:22 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	k;

	k = ft_strlen(s);
	while (*(s + k) != (unsigned char)c && k > 0)
		k--;
	if (*(s + k) == (unsigned char)c)
		return ((char *)s + k);
	return (NULL);
}
/* Search c in sand returns the last occurence if its exist*/
