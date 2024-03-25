/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:09:35 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/16 17:16:47 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function rotates "a" and "b" at the same time */
void    ft_rrab(t_stack **a, t_stack **b)
{
    ft_r(a);
    ft_r(b);
}

/* This function reverse rotates "a" and "b" at the same time */
void    ft_rrrab(t_stack **a, t_stack **b)
{
    ft_rr(a);
    ft_rr(b);
}

void    ft_ss(t_stack **a, t_stack **b)
{
    ft_s(a);
    ft_s(b);
}