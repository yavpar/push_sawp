/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:57:57 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/20 13:47:19 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  This function does:     */
/*  "ra" + "rb"     or 		*/
/*	"sa"			or		*/
/*	"rb"					*/
/*	And then "pb"			*/
void    ft_s_swap(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
ft_printf("\t\t\tdo_op\n");
    if (var_a->dist == 1 && var_b->dist == 1)
    {
		ft_r(a);
		ft_printf("ra\n");
		ft_r(b);
		ft_printf("rb\n");
    }
    else if (var_a->dist == 1 && var_b->dist == 0)
    {
		ft_s(a);
		ft_printf("sa\n");
    }
    else if (var_a->dist == 0 && var_b->dist == 1)
    {
		ft_r(b);
		ft_printf("rb\n");
    }
	ft_push(a, b);
	ft_printf("pb\n");
}
