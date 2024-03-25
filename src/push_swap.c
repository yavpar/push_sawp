/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:10 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/19 20:27:50 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_var_a *var_a;
    t_var_b *var_b;
    
    a = NULL;
    b = NULL;
    var_a = NULL;
    var_b = NULL;
    ft_parse(ac, av, &a);
	var_a = malloc(sizeof(t_var_a));
	var_b = malloc(sizeof(t_var_b));
	if (!var_a || !var_b)
	{
		free_struct(&a, &b, var_a, var_b);
		exit(1);
	}
    if (!is_sort(&a))
		sort_list(&a, &b, var_a, var_b);
    free_struct(&a, &b, var_a, var_b);
    return (0);
}
