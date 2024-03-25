/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:42:33 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 13:43:03 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	k;

	k = 0;
	while (lst != NULL)
	{
		k++;
		lst = lst->next;
	}
	return (k);
}

/* Returns the length of a list */
