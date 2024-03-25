/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:38:00 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/19 22:47:57 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function take the first element of a list "src" and place it    */
/* at the top of another list "dest"                                    */
void    ft_push(t_stack **src, t_stack **dest)
{
    t_stack *temp;
    
    if (src == NULL || *src == NULL)
        return ;
    temp = *src;
    *src = temp->next;
    temp->next = NULL;
    if (*dest == NULL)
        *dest = temp;
    else
    {
        temp->next = *dest;
        *dest = temp;
    }
}

/* ROTATE: This function take the first element of a list and place it at the*/
/* end. The second element becomes the first of the list                */
void    ft_r(t_stack **stack)
{
    t_stack *last_node;
    t_stack *previous_node;

    if (stack == NULL || *stack == NULL)
        return ;
    last_node = *stack;
    *stack = (*stack)->next;
    previous_node = ft_lstlast(*stack);
    previous_node->next = last_node;
    last_node->next = NULL;
}

/*REVERSE ROTATE: This function take the last element of a list and place it*/
/* at the begining (top). The second element becomes the second of the list */
void    ft_rr(t_stack **stack)
{
    t_stack *first_node;
    t_stack *prev;
    
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;
    first_node = *stack;
    while (first_node->next != NULL)
    {
        prev = first_node;
        first_node = first_node->next;
    }
    prev->next = NULL;
    first_node->next = *stack;
    *stack = first_node;
}

/* SWAP: This function take the first element of a list and place it at the*/
/* second place, and the second element becomes the first.                 */
void    ft_s(t_stack **stack)
{
    t_stack *temp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return ;
    temp = (*stack)->next; /*temp es el 2do nodo*/
    (*stack)->next = temp->next; /*el primer nodo apunta el 3er nodo*/
    temp->next = *stack; /*El 2do nodo apunta al primero*/
    *stack = temp; /*ahora stack apunta al primer nodo*/
}

/* This funcion prints a list of type INT                               */
/*
void    print_list(t_stack *stack)
{
    while (stack)
    {
        ft_printf("%d\n", stack->nbr);
        stack = stack->next;
    }
    ft_printf("\n");
}*/