/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_3_nodes_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:48:32 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

int	core_is_3_nodes_312(t_stack *s)
{
	int	d1;
	int	d2;
	int	d3;

	if (!stack_3_nodes_till_bottom_or_pivot(s))
		return (0);
	d1 = s->top->data;
	d2 = s->top->next->data;
	d3 = s->top->next->next->data;
	return (d2 < d3 && d3 < d1);
}

int	core_is_3_nodes_321(t_stack *s)
{
	int	d1;
	int	d2;
	int	d3;

	if (!stack_3_nodes_till_bottom_or_pivot(s))
		return (0);
	d1 = s->top->data;
	d2 = s->top->next->data;
	d3 = s->top->next->next->data;
	return (d3 < d2 && d2 < d1);
}

int	core_3_nodes_is_next_null(t_stack *s)
{
	return (s->top->next->next->next == NULL);
}

void	core_basic_sort_3_nodes(t_stack *a, t_stack *s)
{
	if (core_is_3_nodes_123(s))
		core_operations_3_nodes_123(a, s, core_3_nodes_is_next_null(s));
	else if (core_is_3_nodes_132(s))
		core_operations_3_nodes_132(a, s, core_3_nodes_is_next_null(s));
	else if (core_is_3_nodes_213(s))
		core_operations_3_nodes_213(a, s, core_3_nodes_is_next_null(s));
	else if (core_is_3_nodes_231(s))
		core_operations_3_nodes_231(a, s, core_3_nodes_is_next_null(s));
	else if (core_is_3_nodes_312(s))
		core_operations_3_nodes_312(a, s, core_3_nodes_is_next_null(s));
	else if (core_is_3_nodes_321(s))
		core_operations_3_nodes_321(a, s, core_3_nodes_is_next_null(s));
}
