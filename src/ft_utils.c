/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:29:24 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/19 22:30:06 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function initialice the variables of the struct t_var_a & t_var_b */
void    init_var(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
    var_a->size = ft_lstsize(*a);
    var_b->size = ft_lstsize(*b);
    var_a->dist = INT_MAX / 2;
    var_b->dist = INT_MAX / 2;
    var_a->up = -1;
    var_a->down = -1;
    var_b->up = -1;
    var_b->down = -1;
}
/* This function finds the higher number and puts it in the top of the list */
void    max_to_up(t_stack **b, int size_b)
{
    int i;
        
    i = ind_max_nbr(b);
    if (i > 0)
    {
        if (i <= size_b / 2)
            while (i--)
            {
                ft_r(b);
                ft_printf("rb\n");
            }
        else
        {
            i = size_b - i;
            while (i--)
            {
                ft_rr(b);
                ft_printf("rrb\n");
            }
        }
    }
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

/*  This funcion returns the position of the higher number in the stack */
int	ind_max_nbr(t_stack **stack)
{
	int	max;
	int	i;
    t_stack *temp;
    int k;

	i = 0;
    k = 0;
	max = INT_MIN;
    temp = *stack;
	while (temp)
	{
		if (temp->nbr > max)
		{
			i = k;
			max = temp->nbr;
		}
        k++;
		temp = temp->next;
	}
	return (i);
}
