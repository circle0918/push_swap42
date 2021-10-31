/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:17:42 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	optim_all_more_than_pivot(t_stack *a, int pivot)
{
	t_node	*n;

	n = a->top;
	while (n && !stack_node_is_sorted(n))
	{
		if (n->data < pivot)
			return (0);
		n = n->next;
	}
	return (1);
}

int	optim_all_more_than_pivot_sorted(t_stack *a, int pivot)
{
	t_node	*n;

	n = a->top;
	if (n->data < pivot)
		return (0);
	while (n->next && !stack_node_is_sorted(n))
	{
		if (n->data > n->next->data)
			return (0);
		n = n->next;
	}
	return (1);
}

int	optim_all_less_than_pivot(t_stack *a, int pivot)
{
	t_node	*n;

	n = a->top;
	while (n && !stack_node_is_sorted(n))
	{
		if (n->data > pivot)
			return (0);
		n = n->next;
	}
	return (1);
}

int	optim_all_less_than_pivot_sorted(t_stack *b)
{
	t_node	*n;

	n = b->top;
	while (n->next && !stack_is_node_pivot(n->next))
	{
		if (n->data < n->next->data)
			return (0);
		n = n->next;
	}
	return (1);
}

int	optim_is_first_round_a(t_stack *a)
{
	t_node	*n;

	n = a->top;
	while (n)
	{
		if (n->is_sorted)
			return (0);
		n = n->next;
	}
	return (1);
}
