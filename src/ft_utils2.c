/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:55:40 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/19 20:26:21 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  This function checks if the stack is in ascending order   */
int is_sort(t_stack **stack)
{
    t_stack *temp;
    
    temp = *stack;
    while (temp)
    {
        if (temp->nbr > temp->next->nbr)
            return (0);
        temp = temp->next;
    }
    return (1);
}

void    ft_free_stack(t_stack **stack)
{
    t_stack *temp;

    if (stack && *stack)
        while (*stack)  
        {
            temp = *stack;
            *stack = (*stack)->next;
            free (temp);
        }
}

void    free_struct(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	if (var_a)
		free(var_a);
	if (var_b)
		free(var_b);
	if (a || *a)
		ft_free_stack(a);
	if (b || *b)
		ft_free_stack(b);
}