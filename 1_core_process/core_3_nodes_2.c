/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_3_nodes_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:48:13 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

void	core_operations_3_nodes_321(t_stack *a, t_stack *s, int isNextNull)
{
	if (!a && isNextNull)
	{
		sa(s);
		rra(s);
	}
	else if (!a && !isNextNull)
	{
		sa(s);
		ra(s);
		sa(s);
		rra(s);
		sa(s);
	}
	else if (a && isNextNull)
	{
		pa(a, s);
		pa(a, s);
		pa(a, s);
	}
	else if (a && !isNextNull)
	{
		pa(a, s);
		pa(a, s);
		pa(a, s);
	}
}

int	core_is_3_nodes_123(t_stack *s)
{
	int	d1;
	int	d2;
	int	d3;

	if (!stack_3_nodes_till_bottom_or_pivot(s))
		return (0);
	d1 = s->top->data;
	d2 = s->top->next->data;
	d3 = s->top->next->next->data;
	return (d1 < d2 && d2 < d3);
}

int	core_is_3_nodes_132(t_stack *s)
{
	int	d1;
	int	d2;
	int	d3;

	if (!stack_3_nodes_till_bottom_or_pivot(s))
		return (0);
	d1 = s->top->data;
	d2 = s->top->next->data;
	d3 = s->top->next->next->data;
	return (d1 < d3 && d3 < d2);
}

int	core_is_3_nodes_213(t_stack *s)
{
	int	d1;
	int	d2;
	int	d3;

	if (!stack_3_nodes_till_bottom_or_pivot(s))
		return (0);
	d1 = s->top->data;
	d2 = s->top->next->data;
	d3 = s->top->next->next->data;
	return (d2 < d1 && d1 < d3);
}

int	core_is_3_nodes_231(t_stack *s)
{
	int	d1;
	int	d2;
	int	d3;

	if (!stack_3_nodes_till_bottom_or_pivot(s))
		return (0);
	d1 = s->top->data;
	d2 = s->top->next->data;
	d3 = s->top->next->next->data;
	return (d3 < d1 && d1 < d2);
}
