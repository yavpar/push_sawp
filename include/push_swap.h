/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:29:25 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/19 20:28:23 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib_c/libft/libft.h"
#include "../lib_c/ft_printf/ft_printf.h"

typedef struct          s_stack
{
    int                 nbr;
    struct s_stack      *next;
}                       t_stack;

typedef struct          s_var_a
{
    int size;
    int dist;
    int up;
    int down;
}                       t_var_a;

typedef struct          s_var_b
{
    int size;
    int dist;
    int up;
    int down;
}                       t_var_b;

/*  FOR PARSING */
void                    ft_parse(int ac, char **av, t_stack **a);
int                     valid_sintax(char **s, int size_data);

/*  PRIMITIVE OPERATIONS WITH LIST */
int	                    ft_lstsize(t_stack *lst);
t_stack                 *ft_lstlast(t_stack *stack);
t_stack	                *ft_lstnew(int content);

/*  BASIC OPERATION WITH LIST   */
void                    ft_push(t_stack **src, t_stack **dest);
void                    ft_r(t_stack **stack);
void                    ft_rr(t_stack **stack);
void                    ft_s(t_stack **stack);
void                    ft_ss(t_stack **a, t_stack **b);
void    				ft_rrab(t_stack **a, t_stack **b);
void    				ft_rrrab(t_stack **a, t_stack **b);

/*  DERIVATE OPERATIONS WITH LIST   */
void    				ft_s_swap(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
void					ft_rotate(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
void					ft_rev_rotate(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
void					ft_mix_rot(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);

/*  FOR CALCULS TO FIND THE NODES TO MOVE*/
void					sort_list(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
void					node_to_move(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
int						find_dist_b(t_stack **stack, int nbr, int size_b, int *pos_b);

/*  UTILS */
int						ind_max_nbr(t_stack **stack);
void					ft_error(void);
void					ft_free_stack(t_stack **stack);
void					free_struct(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
int						is_sort(t_stack **stack);
void					free_struct(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);
void					init_var(t_stack **a, t_stack **b, t_var_a *var_a, t_var_b *var_b);

/*  FOR BONUS */

// void	read_and_exec(t_stack **a, t_stack **b, char *cmd);
// void	check_list(char *cmd, t_stack **a);
// void	free_lists(t_stack **a, t_stack **b);
// void	ft_exec(t_stack **a, t_stack **b, char *cmd);
// void	ft_syntax_error(t_stack **a, t_stack **b, char *cmd);
// int	is_list_sorted(t_stack **stack);
# endif
