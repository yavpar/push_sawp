/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:57:49 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/20 13:49:10 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This fonction does: 	*/
/*	"rr"			or		*/
/*	"rb" + "rr"		or		*/
/*	"ra" + "rr"				*/
/*	and then "pb"			*/
static void	rbrr(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
static void	rarr(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);

void	ft_rotate(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	int	k;
printf("\t\t\tdo_op\n");
	k = -1;
	if (var_a->dist == var_b->dist)
	{
		while (++k < var_a->dist)
		{
			ft_rrab(a, b);
			ft_printf("rr\n");
		}
	}
	else if (var_a->dist < var_b->dist)
		rbrr(a, b, var_a, var_b);
	else if (var_a->dist > var_b->dist)
		rarr(a, b, var_a, var_b);
	ft_push(a, b);
	ft_printf("pb\n");
}

static void	rbrr(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	int	dist;
	int	k;
	
	k = -1;
	dist = var_b->dist - var_a->dist;
	while (++k < var_a->dist)
	{	
		ft_rrab(a, b);
		ft_printf("rr\n");
	}
	k = -1;
	while (++k < dist)
	{
		ft_r(b);
		ft_printf("rb\n");
	}
}

static void	rarr(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	int	dist;
	int	k;

	k= -1;
	dist = var_a->dist - var_b->dist;
	while (++k < var_b->dist)
	{
		ft_rrab(a, b);
		ft_printf("rr\n");
	}
	k = -1;
	while (++k < dist)
	{
		ft_r(a);
		ft_printf("ra\n");
	}
}
