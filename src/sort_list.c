/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:09:10 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/20 13:52:42 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_2(t_stack **a, t_stack **b);
static void	do_operation(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
static void	sort_three(t_stack **list, int to_print);
static void	max_to_up(t_stack **b, int size_b);

void	sort_list(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	int	k;

	if (ft_lstsize(*a) < 4)
		sort_three(a, 1);
	else
	{
		push_2(a, b);
		k = ft_lstsize(*a);
		init_var(a, b, var_a, var_b);
		while (k-- > 0)
		{
			node_to_move(a, b, var_a, var_b);
			do_operation(a, b, var_a, var_b);
			init_var(a, b, var_a, var_b);
		}
		k = ft_lstsize(*b);
		max_to_up(b, k);
		while (k-- > 0)
		{
			ft_push(b, a);
			ft_printf("pa\n");
		}
	}
}

static void	push_2(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_push(a, b);
	ft_printf("pb\n");
	ft_printf("pb\n");
	if ((*b)->nbr < (*b)->next->nbr)
	{
		ft_s(b);
		ft_printf("sb\n");
	}
}

static void	sort_three(t_stack **list, int to_print)
{
	int	i;
	
	if (ft_lstsize(*list) == 1)
		return ;
	i = ind_max_nbr(list);
	if (i == 0)
	{
		ft_r(list);
		if (to_print == 1)
			ft_printf("ra\n");
	}
	else if (i == 1)
	{
		ft_rr(list);
		if (to_print == 1)
			ft_printf("rra\n");
	}
	if ((*list)->nbr > (*list)->next->nbr)
	{
		ft_s(list);
		if (to_print == 1)
			ft_printf("sa\n");
	}
}

static void	do_operation(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
printf("\t\t***variables choisi***\n");
printf("a-up = %d\na-down = %d\nb-up = %d\nb-down = %d\n", var_a->up, var_a->down, var_b->up, var_b->down);
printf("a-dist = %d\nb-dist= %d\n\n", var_a->dist, var_b->dist);

	if (var_a->up == 1 && var_b->up == 1)
	{
		if (var_a->dist == 0 && var_b->dist == 0)
		{
ft_printf("\t\t\tdo_op\n");
			ft_push(a, b);
			ft_printf("pb\n");
		}
		else if (var_a->dist <= 1 && var_b->dist <= 1)
			ft_s_swap(a, b, var_a, var_b);
		else
			ft_rotate(a, b, var_a, var_b);
	}
	else if (var_a->down == 1 && var_b->down == 1)
		ft_rev_rotate(a, b, var_a, var_b);
	else
		ft_mix_rot(a, b, var_a, var_b);
}

static void    max_to_up(t_stack **b, int size_b)
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
