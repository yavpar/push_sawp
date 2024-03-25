/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:27:26 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/16 16:01:43 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* this funcion returns the size of a list */

int	ft_lstsize(t_stack *lst)
{
	int	k;
	t_stack	*temp;

	k = 0;
	temp = lst;
	while (temp)
	{
		k++;
		temp = temp->next;
	}
	return (k);
}

/* This function returns the last node of a list */

t_stack *ft_lstlast(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!temp)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/* This function allocates memory and returns a new node */
/* It contains a variable of type INT					 */

t_stack	*ft_lstnew(int content)
{
	t_stack	*n_node;

	n_node = (t_stack *)malloc(sizeof(t_stack));
	if (!n_node)
		return (NULL);
	n_node->nbr = content;
	n_node->next = NULL;
	return (n_node);
}
