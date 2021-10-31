/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:12:47 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_top_is_sorted(t_stack *s)
{
	return (s->top->is_sorted == 1);
}

int	stack_node_is_sorted(t_node *n)
{
	return (n->is_sorted == 1);
}

t_node	*stack_get_bottom_node(t_stack *s)
{
	t_node	*n;

	n = s->top;
	while (n->next)
		n = n->next;
	return (n);
}

int	stack_node_number(t_stack *s)
{
	int		num;
	t_node	*n;

	num = 0;
	n = s->top;
	while (n)
	{
		num++;
		n = n->next;
	}
	return (num);
}

int	stack_is_sorted_number(t_stack *a)
{
	int		num;
	t_node	*n;

	num = 0;
	n = a->top;
	while (n)
	{
		if (n->is_sorted)
			num++;
		n = n->next;
	}
	return (num);
}
