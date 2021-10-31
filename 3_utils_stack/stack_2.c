/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:11:42 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_push(t_stack *s, int d)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->data = d;
	tmp->next = NULL;
	tmp->is_pivot = 0;
	tmp->by_pivot = 0;
	tmp->is_sorted = 0;
	if (stack_is_empty(s))
		s->top = tmp;
	else
	{
		tmp->next = s->top;
		s->top = tmp;
	}
}

int	stack_peek_data(t_stack *s)
{
	if (stack_is_empty(s))
	{
		return (-1);
	}
	return (s->top->data);
}

int	stack_set_top_pivot(t_stack *s)
{
	s->top->is_pivot = 1;
	return (stack_peek_data(s));
}

int	stack_is_node_pivot(t_node *n)
{
	return (n->is_pivot == 1);
}
