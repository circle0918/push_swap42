/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:20:00 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_set_by_pivot(t_stack *s, int p)
{
	s->top->by_pivot = p;
}

int	stack_get_top_by_pivot(t_stack *s)
{
	return (s->top->by_pivot);
}

int	stack_get_node_by_pivot(t_node *n)
{
	return (n->by_pivot);
}

void	stack_set_top_is_sorted(t_stack *s)
{
	s->top->is_sorted = 1;
}

void	stack_set_node_is_sorted(t_node *n)
{
	n->is_sorted = 1;
}
