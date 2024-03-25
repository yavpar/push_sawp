/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_to_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:05:55 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/19 21:50:18 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This funcion calculates the shorter distance of two nodes to put	*/
/* at the top of the lists "a" and "b" */
static void	set_dist(t_var_a *var_a, t_var_b *var_b, int dist_ta, int dist_tb);
static void	set_position(t_var_a *var_a, t_var_b *var_b, int a, int b);
static int	dist_temp_a(int i, int size_list);

void	node_to_move(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b)
{
	int	pos_a;
	int	pos_b;
	int	dist_ta;
	int	dist_tb;
	t_stack	*temp_a;

	pos_a = -1;
	pos_b = -1;
	temp_a = *a;
	while (temp_a != NULL)
	{
		dist_ta = dist_temp_a(++pos_a, var_a->size);
		dist_tb = find_dist_b(b, temp_a->nbr, var_b->size, &pos_b);
		if ((dist_tb + dist_ta) < (var_a->dist + var_b->dist))
		{
			set_dist(var_a, var_b, dist_ta, dist_tb);
			set_position(var_a, var_b, pos_a, pos_b);
		}
		temp_a = temp_a->next;
	}
}

/* This function sets the distance to put the node in "a" at the top */
static int	dist_temp_a(int i, int size_list)
{
	int	dist;

	dist = 0;
	if (i <= size_list / 2)
		dist = i;
	else if (i > size_list / 2)
		dist = size_list - i;
	return (dist);
}

/* This function stablishes whether the nodes are above or below	*/
/* the median size of the lists. 									*/
static void	set_position(t_var_a *var_a, t_var_b *var_b, int a, int b)
{
	var_a->up = -1;
    var_a->down = -1;
    var_b->up = -1;
    var_b->down = -1;
	if (a <= var_a->size / 2)
		var_a->up = 1;
	else
		var_a->down = 1;
	if (b <= var_b->size / 2)
		var_b->up = 1;
	else
		var_b->down = 1;
}

static void	set_dist(t_var_a *var_a, t_var_b *var_b, int dist_ta, int dist_tb)
{
	var_a->dist = dist_ta;
	var_b->dist = dist_tb;
}


