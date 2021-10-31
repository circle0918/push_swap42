/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_b2a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:51:48 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	core_basic_sort_b(t_stack *a, t_stack *s)
{
	if (stack_0_nodes_till_bottom_or_pivot(s))
		return ;
	else if (stack_1_nodes_till_bottom_or_pivot(s))
	{
		stack_set_top_is_sorted(s);
		pa(a, s);
	}
	else if (stack_2_nodes_till_bottom_or_pivot(s))
	{
		stack_set_node_is_sorted(s->top);
		stack_set_node_is_sorted(s->top->next);
		if (s->top->data < s->top->next->data)
			sb(s);
		pa(a, s);
		pa(a, s);
	}
	else if (stack_3_nodes_till_bottom_or_pivot(s))
	{
		stack_set_node_is_sorted(s->top);
		stack_set_node_is_sorted(s->top->next);
		stack_set_node_is_sorted(s->top->next->next);
		core_basic_sort_3_nodes(a, s);
	}
}

static void	core_b2a(t_stack *a, t_stack *b)
{
	if (optim_all_less_than_pivot_sorted(b))
	{
		while (!stack_is_empty(b) && !stack_is_top_pivot(b))
		{
			stack_set_top_is_sorted(b);
			pa(a, b);
		}
		return ;
	}
	optim_b2a_pa_bigger_than_top(a, b);
}

void	core_b2a_while(t_stack *a, t_stack *b)
{
	int	stop;

	if (stack_is_empty(b))
		return ;
	stop = 0;
	while (!stack_is_empty(b) && !stop)
	{
		stack_set_top_is_sorted(b);
		pa(a, b);
		if (core_if_do_basic_sort(b))
			core_basic_sort_b(a, b);
		else
		{
			stop = 1;
			core_b2a(a, b);
		}
	}
}
