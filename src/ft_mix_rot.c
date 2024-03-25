/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:57:28 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/20 13:49:04 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This fonction does: 	*/
/*	"rra" + "rb"	or		*/
/*	"rrb" + "ra"			*/
/*	and then "pb"			*/
static void mix_rot_2(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);

void    ft_mix_rot(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
    int k;
printf("\t\t\tdo_op\n");
    k = -1;
    if (var_a->up == 1 && var_b->down == 1)
    {
        while (++k < var_a->dist)
        {
            ft_r(a);
            ft_printf("ra\n");   
        }
        k = -1;
        while (++k < var_b->dist)
        {
            ft_rr(b);
            ft_printf("rrb\n");  
        }
    }
    else if (var_a->down == 1 && var_b->up == 1)
        mix_rot_2(a, b, var_a, var_b);
    ft_push(a, b);
    ft_printf("pb\n");
}

static void mix_rot_2(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{    
    int k;
    
    k = -1;
    while (++k < var_a->dist)
    {
        ft_rr(a);
        ft_printf("rra\n");
    }
    k = -1;
    while (++k < var_b->dist)
    {
        ft_r(b);
        ft_printf("rb\n");
    }
}