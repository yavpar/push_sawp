/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_dist_in_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:03:57 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/20 12:05:54 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function verifies if the number is the biggest of a list	*/
static int    verif_max(t_stack **b, int nbr)
{
    t_stack *stack;

    stack = *b;
    while (stack)
    {
		if (nbr < stack->nbr)
			return (0);
        stack = stack->next;
    }
    return (1);
}

/* This function verifies if the number is the minor of a list	*/
static int    verif_min(t_stack **b, int nbr)
{
    t_stack *stack;

    stack = *b;
    while (stack)
    {
		if (nbr > stack->nbr)
			return (0);
        stack = stack->next;
    }
    return (1);
}

/* Sets the distance of the chosen node to the top of the list    */
static int	dist_temp(int i, int size_list, int *pos)
{
	int	dist;

	dist = 0;
	*pos = i;
	if (i <= size_list / 2)
		dist = i;
	else
		dist = size_list - i;
	return (dist);
}

/* This function calculates the position to put "nbr" in the "stack b" */
int	find_dist_b(t_stack **stack, int nbr, int size_b, int *pos_b)
{
	t_stack	*tmp;
    t_stack *actual;
    int i_actual;
	int	dist;
    
    i_actual = 1;
	actual = *stack;
	dist = -1;
	if (nbr > actual->nbr && nbr < ft_lstlast(*stack)->nbr)
		dist = dist_temp(0, size_b, pos_b);
	else if (verif_max(stack, nbr) || verif_min(stack, nbr))
		dist = dist_temp(ind_max_nbr(stack), size_b, pos_b);
	else
	{
		tmp = actual->next;
		while (actual->nbr < nbr || tmp->nbr > nbr)
		{
			actual = actual->next;
			tmp = actual->next;
			i_actual++;
		}
		dist = dist_temp(i_actual, size_b, pos_b);
	}
	return (dist);
}
