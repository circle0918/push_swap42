/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_a2b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:50:38 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

void	core_a2b_push_as_many_as_pb(t_stack *a, t_stack *b, int pivot)
{
	while (!stack_is_empty(a) && !stack_top_is_sorted(a))
	{
		if (optim_all_more_than_pivot(a, pivot))
			return ;
		if (stack_peek_data(a) < pivot)
			pb(a, b);
		else
			return ;
	}
}

int	core_a2b_count_ra_while_pb_or_ra(t_stack *a, t_stack *b, int pivot)
{
	int	count_ra;

	count_ra = 0;
	while (!stack_is_empty(a)
		&& !stack_top_is_sorted(a)
		&& stack_get_top_by_pivot(a) != pivot)
	{
		if (optim_all_more_than_pivot(a, pivot))
			break ;
		stack_set_by_pivot(a, pivot);
		if (stack_peek_data(a) < pivot)
			pb(a, b);
		else
		{
			count_ra++;
			ra(a);
		}
	}
	return (count_ra);
}

void	core_a2b_ra_rra(t_stack *a, int pivot, int count_ra_done)
{
	int	count_ra_needed;

	if (count_ra_done != 0)
	{
		count_ra_needed = core_count_ra_needed_till_by_pivot(a, pivot);
		if (count_ra_done > count_ra_needed)
		{
			while (count_ra_needed--)
				ra(a);
		}
		else
		{
			while (count_ra_done--)
				rra(a);
		}	
	}
}

void	core_a2b(t_stack *a, t_stack *b)
{
	int	pivot;
	int	is_b_empty_before_pb;
	int	count_ra_done;

	pivot = stack_set_top_pivot(a);
	if (optim_a2b_pivot_is_biggest(a, pivot))
		return ;
	if (optim_a2b_pivot_is_smallest_sorted(a, pivot))
		return ;
	is_b_empty_before_pb = stack_is_empty(b);
	pb(a, b);
	if (optim_all_more_than_pivot(a, pivot))
		return ;
	if (!is_b_empty_before_pb)
		rb(b);
	core_a2b_push_as_many_as_pb(a, b, pivot);
	optim_a2b_first_round_rra(a, b, pivot);
	count_ra_done = core_a2b_count_ra_while_pb_or_ra(a, b, pivot);
	core_a2b_ra_rra(a, pivot, count_ra_done);
	if (!(b->top->next == NULL && b->top->is_pivot == pivot))
		rrb(b);
}

void	core_a2b_while(t_stack *a, t_stack *b)
{
	while (!core_if_do_basic_sort(a))
	{
		core_a2b(a, b);
	}
}
