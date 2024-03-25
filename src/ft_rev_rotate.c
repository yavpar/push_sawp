/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:57:39 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/20 13:48:57 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This fonction does: 	*/
/*	"rrr"			or		*/
/*	"rra" + "rrr"	or		*/
/*	"rrb" + "rrr"			*/
/*	and then "pb"			*/
static void	rrbrrr(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
static void	rrarrr(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);

void	ft_rev_rotate(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	int	k;
printf("\t\t\tdo_op\n");
	k = -1;
	if (var_a->dist == var_b->dist)
	{
		while (++k < var_a->dist)
		{
			ft_rrrab(a, b);
			ft_printf("rrr\n");
		}
	}
	else if (var_a->dist < var_b->dist)
		rrbrrr(a, b, var_a, var_b);
	else if (var_a->dist > var_b->dist)
		rrarrr(a, b, var_a, var_b);
	ft_push(a, b);
	ft_printf("pb\n");
}

static void	rrbrrr(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	int	dist;
	int	k;

	k = -1;
	dist = var_b->dist - var_a->dist;
	while (++k < var_a->dist)
	{
		ft_rrrab(a, b);
		ft_printf("rrr\n");
	}
	k = -1;
	while (++k < dist)
	{
		ft_rr(b);
		ft_printf("rrb\n");
	}
}

static void	rrarrr(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	int	dist;
	int	k;
	
	k= -1;
	dist = var_a->dist - var_b->dist;
	while (++k < var_b->dist)
	{
		ft_rrrab(a, b);
		ft_printf("rrr\n");
	}
	k = -1;
	while (++k < dist)
	{
		ft_rr(a);
		ft_printf("rra\n");
	}
}