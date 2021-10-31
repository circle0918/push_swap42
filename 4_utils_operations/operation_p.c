/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:28:22 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	operation_p(t_stack *from, t_stack *to)
{
	t_node	*top;

	if (stack_is_empty(from))
	{
		return (1);
	}
	top = stack_pop(from);
	top->next = to->top;
	to->top = top;
	return (0);
}

void	pb(t_stack *a, t_stack *b)
{
	operation_p(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	operation_p(b, a);
	write(1, "pa\n", 3);
}
