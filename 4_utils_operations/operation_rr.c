/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:14:02 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	operation_rr(t_stack *s)
{
	t_node	*before_bottom;
	t_node	*bottom;

	if (s->top->next == NULL)
		return ;
	before_bottom = s->top;
	while (before_bottom->next->next != NULL)
	{
		before_bottom = before_bottom->next;
	}
	bottom = before_bottom->next;
	before_bottom->next = NULL;
	bottom->next = s->top;
	s->top = bottom;
}

void	rra(t_stack *s)
{
	operation_rr(s);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *s)
{
	operation_rr(s);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	operation_rr(a);
	operation_rr(b);
	write(1, "rrr\n", 4);
}
