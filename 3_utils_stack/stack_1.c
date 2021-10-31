/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:23:52 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
}

int	stack_is_empty(t_stack *s)
{
	return (s->top == NULL);
}

void	stack_free(t_stack *s)
{
	t_node	*top;

	while (!stack_is_empty(s))
	{
		top = stack_pop(s);
		free(top);
	}
	free(s);
}

//pop top node ptr, update s to new top
t_node	*stack_pop(t_stack *s)
{
	t_node	*top_node;

	if (stack_is_empty(s))
		return (NULL);
	top_node = s->top;
	s->top = top_node->next;
	top_node->next = NULL;
	return (top_node);
}
