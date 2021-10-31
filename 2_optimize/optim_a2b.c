/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optim_a2b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:09:47 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	optim_a2b_pivot_is_biggest(t_stack *a, int pivot)
{
	if (optim_all_less_than_pivot(a, pivot))
	{
		if (optim_is_first_round_a(a))
		{
			ra(a);
			return (1);
		}
	}
	return (0);
}

int	optim_a2b_pivot_is_smallest_sorted(t_stack *a, int pivot)
{
	t_node	*n;

	if (optim_all_more_than_pivot_sorted(a, pivot))
	{
		n = a->top;
		while (n && !stack_node_is_sorted(n))
		{
			stack_set_node_is_sorted(n);
			n = n->next;
		}	
		return (1);
	}
	return (0);
}

void	optim_a2b_first_round_rra(t_stack *a, t_stack *b, int pivot)
{
	int	count_rra;

	if (optim_is_first_round_a(a))
	{
		if (optim_may_need_rra(a, pivot))
		{
			count_rra = optim_count_rra_if_better(a, pivot);
			{
				if (count_rra)
				{
					while (count_rra--)
					{
						rra(a);
						pb(a, b);
					}
				}
			}
		}
	}
}

void	optim_b2a_pa_bigger_than_top(t_stack *a, t_stack *b)
{
	int	pivot;
	int	count_rb;

	pivot = stack_set_top_pivot(b);
	rb(b);
	count_rb = 1;
	while (!stack_is_empty(b) && !stack_is_top_pivot(b))
	{
		if (b->top->data > pivot)
			pa(a, b);
		else
		{
			count_rb++;
			rb(b);
		}
	}
	while (count_rb--)
		rrb(b);
}
