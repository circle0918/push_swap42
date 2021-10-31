/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:13:44 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	operation_r(t_stack *s)
{
	t_node	*bottom;
	t_node	*top;

	if (s->top->next == NULL)
		return ;
	bottom = s->top;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}
	top = stack_pop(s);
	bottom->next = top;
}

void	ra(t_stack *s)
{
	operation_r(s);
	write(1, "ra\n", 3);
}

void	rb(t_stack *s)
{
	operation_r(s);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	operation_r(a);
	operation_r(b);
	write(1, "rr\n", 3);
}
