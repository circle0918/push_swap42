/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:28:46 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_s(t_stack *s)
{
	t_node	*top_node;

	if (s->top->next == NULL)
		return ;
	top_node = stack_pop(s);
	top_node->next = s->top->next;
	s->top->next = top_node;
}

void	sa(t_stack *s)
{
	operation_s(s);
	write (1, "sa\n", 3);
}

void	sb(t_stack *s)
{
	operation_s(s);
	write (1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	operation_s(a);
	operation_s(b);
	write(1, "ss\n", 3);
}
