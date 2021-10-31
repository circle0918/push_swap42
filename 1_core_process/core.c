/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:05:00 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	core_count_ra_needed_till_by_pivot(t_stack *a, int pivot)
{
	t_node	*n;
	int		count;

	n = a->top;
	count = 0;
	while (stack_get_node_by_pivot(n) != pivot)
	{
		count++;
		n = n->next;
	}
	return (count);
}

int	core_if_do_basic_sort(t_stack *s)
{
	if (stack_0_nodes_till_bottom_or_pivot(s))
		return (1);
	if (stack_1_nodes_till_bottom_or_pivot(s))
		return (1);
	if (stack_2_nodes_till_bottom_or_pivot(s))
		return (1);
	if (stack_3_nodes_till_bottom_or_pivot(s))
		return (1);
	return (0);
}

void	core_basic_sort_a(t_stack *s)
{
	if (stack_0_nodes_till_bottom_or_pivot(s))
		return ;
	else if (stack_1_nodes_till_bottom_or_pivot(s))
	{
		stack_set_top_is_sorted(s);
		return ;
	}
	else if (stack_2_nodes_till_bottom_or_pivot(s))
	{	
		stack_set_node_is_sorted(s->top);
		stack_set_node_is_sorted(s->top->next);
		if (s->top->data > s->top->next->data)
			sa(s);
	}
	else if (stack_3_nodes_till_bottom_or_pivot(s))
	{
		stack_set_node_is_sorted(s->top);
		stack_set_node_is_sorted(s->top->next);
		stack_set_node_is_sorted(s->top->next->next);
		core_basic_sort_3_nodes(NULL, s);
	}
}

void	core_process(t_stack *a, t_stack *b)
{
	int	stop_process;

	stop_process = 0;
	while (!stop_process)
	{
		core_a2b_while(a, b);
		core_basic_sort_a(a);
		if (stack_is_empty(b))
		{
			stop_process = 1;
			continue ;
		}
		core_b2a_while(a, b);
	}
}
