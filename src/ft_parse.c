/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:40:05 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/19 22:58:53 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/*  PARSE:  this fonction checks the arguments passed in the command line.  */
/*  It verifies if there are arguments and if it's so, checks if they are:  */
/*  Valid characters: "-+0123456789"                                        */
/*  INTEGER types: INT_MIN <= nbr <= INT_MAX                                */
/*  Unique numbers                                                          */
/*  Then creates a linked list */
static void    create_stack(t_stack **stack, char **s, int size_stack);
static void    ft_parse_string(char *t, t_stack **a);
static void    ft_parse_list(char **av, int ac, t_stack **a);

void    ft_parse(int ac, char **av, t_stack **a)
{
	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		exit(1);
	if (ac == 2)
		ft_parse_string(av[1], a);
	else if (ac > 2)
		ft_parse_list(&av[1], ac - 1, a);  
}


static void    ft_parse_list(char **av, int ac, t_stack **a)
{
    if (valid_sintax(av, ac) == 0)
        ft_error();
    create_stack(a, av, ac);
}

static void    ft_parse_string(char *t, t_stack **a)
{
    int size_s;
    char    **s;
    
    s = ft_split(t, ' ');
    if (!s)
       ft_error();
    size_s = 0;
    while (s[size_s])
        size_s++;
    if (valid_sintax(s, size_s) == 0)
    {
        ft_free_array((void **)s, size_s, (void (*)(void *))ft_free);
        ft_error();
    }
    create_stack(a, s, size_s);
    ft_free_array((void **)s, size_s, (void (*)(void *))ft_free);
}

static void    create_stack(t_stack **stack, char **s, int size_stack)
{
    t_stack *new_node;
    int k;

    k = -1;
    if (!stack)
    {
        ft_free_array((void **)s, size_stack, (void (*)(void *))ft_free);
        ft_error();
    }
    while ((++k < size_stack) && s[k] != NULL)
    {
        new_node = ft_lstnew(ft_atoi(s[k]));
        if (!new_node || s[k] == NULL)
        {
            ft_free_array((void **)s, size_stack, (void (*)(void *))ft_free);
            ft_free_stack(stack);
            ft_error();
        }
        if (*stack == NULL)
            *stack = new_node;
        else
            ft_lstlast(*stack)->next = new_node;
    }
}
