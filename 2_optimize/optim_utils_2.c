/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:08:20 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	optim_may_need_rra(t_stack *a, int pivot)
{
	t_node	*n;

	if (!a->top || !a->top->next || !a->top->next->next)
		return (0);
	n = a->top;
	while (n->next)
	{
		if (n->data < pivot && n->next->data > pivot)
			return (0);
		n = n->next;
	}
	if (n->data > pivot)
		return (0);
	return (1);
}

int	optim_count_rra_if_better(t_stack *a, int pivot)
{
	t_node	*n;
	int		is_better;
	int		count;

	n = a->top;
	is_better = 0;
	count = 0;
	while (n)
	{
		if (n->data > pivot)
			is_better++;
		else
		{
			is_better--;
			count++;
		}
		n = n->next;
	}
	if (is_better > 0)
		return (count);
	else
		return (0);
}
