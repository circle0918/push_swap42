/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:35:12 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 21:33:48 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	int				is_pivot;
	int				by_pivot;
	int				is_sorted;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

//0      
int			push_args_safely(t_stack *a, int ac, char **av);
long long	ft_atoll(const char *str);

//1
void		core_process(t_stack *a, t_stack *b);
void		core_a2b_while(t_stack *a, t_stack *b);
void		core_b2a_while(t_stack *a, t_stack *b);
int			core_if_do_basic_sort(t_stack *s);
void		core_basic_sort_3_nodes(t_stack *a, t_stack *s);
int			core_is_3_nodes_123(t_stack *s);
int			core_is_3_nodes_132(t_stack *s);
int			core_is_3_nodes_213(t_stack *s);
int			core_is_3_nodes_231(t_stack *s);
int			core_is_3_nodes_312(t_stack *s);
int			core_is_3_nodes_321(t_stack *s);
void		core_operations_3_nodes_123(t_stack *a, t_stack *s, int isNextNull);
void		core_operations_3_nodes_132(t_stack *a, t_stack *s, int isNextNull);
void		core_operations_3_nodes_213(t_stack *a, t_stack *s, int isNextNull);
void		core_operations_3_nodes_231(t_stack *a, t_stack *s, int isNextNull);
void		core_operations_3_nodes_312(t_stack *a, t_stack *s, int isNextNull);
void		core_operations_3_nodes_321(t_stack *a, t_stack *s, int isNextNull);
int			optim_may_need_rra(t_stack *a, int pivot);
int			core_count_ra_needed_till_by_pivot(t_stack *a, int pivot);

//2
int			optim_a2b_pivot_is_biggest(t_stack *a, int pivot);
int			optim_a2b_pivot_is_smallest_sorted(t_stack *a, int pivot);
void		optim_a2b_first_round_rra(t_stack *a, t_stack *b, int pivot);
int			optim_all_more_than_pivot(t_stack *a, int pivot);
int			optim_all_more_than_pivot_sorted(t_stack *a, int pivot);
int			optim_all_less_than_pivot(t_stack *a, int pivot);
int			optim_all_less_than_pivot_sorted(t_stack *b);
void		optim_b2a_pa_bigger_than_top(t_stack *a, t_stack *b);
int			optim_all_less_than_pivot(t_stack *a, int pivot);
int			optim_is_first_round_a(t_stack *a);
int			optim_count_rra_if_better(t_stack *a, int pivot);

//3
void		stack_init(t_stack *s);
t_node		*stack_pop(t_stack *s);
void		stack_push(t_stack *s, int d);
void		stack_free(t_stack *s);
int			stack_is_empty(t_stack *s);
int			stack_peek_data(t_stack *s);
int			stack_is_top_pivot(t_stack *s);
int			stack_set_top_pivot(t_stack *s);
int			stack_is_node_pivot(t_node *s);
int			stack_is_node_pivot(t_node *n);
void		stack_set_by_pivot(t_stack *s, int p);
int			stack_get_top_by_pivot(t_stack *s);
int			stack_get_node_by_pivot(t_node *n);
int			stack_0_nodes_till_bottom_or_pivot(t_stack *s);
int			stack_1_nodes_till_bottom_or_pivot(t_stack *s);
int			stack_2_nodes_till_bottom_or_pivot(t_stack *s);
int			stack_3_nodes_till_bottom_or_pivot(t_stack *s);
void		stack_set_top_is_sorted(t_stack *s);
int			stack_top_is_sorted(t_stack *s);
void		stack_set_node_is_sorted(t_node *n);
int			stack_top_is_sorted(t_stack *s);
int			stack_node_is_sorted(t_node *n);

//4
void		sa(t_stack *s);
void		sb(t_stack *s);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *s);
void		rb(t_stack *s);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *s);
void		rrb(t_stack *s);
void		rrr(t_stack *a, t_stack *b);

#endif
