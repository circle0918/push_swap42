/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:12:07 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_is_top_pivot(t_stack *s)
{
	return (stack_is_node_pivot(s->top));
}

int	stack_0_nodes_till_bottom_or_pivot(t_stack *s)
{
	return (stack_is_empty(s) || stack_is_top_pivot(s));
}

int	stack_1_nodes_till_bottom_or_pivot(t_stack *s)
{
	return (s->top->next == NULL || stack_is_node_pivot(s->top->next));
}

int	stack_2_nodes_till_bottom_or_pivot(t_stack *s)
{
	return (s->top->next->next == NULL
		|| stack_is_node_pivot(s->top->next->next));
}

int	stack_3_nodes_till_bottom_or_pivot(t_stack *s)
{
	return (s->top->next->next->next == NULL
		|| stack_is_node_pivot(s->top->next->next->next));
}
