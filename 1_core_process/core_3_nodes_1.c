/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_3_nodes_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:47:51 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

void	core_operations_3_nodes_123(t_stack *a, t_stack *s, int isNextNull)
{
	if (!a && isNextNull)
		return ;
	else if (!a && !isNextNull)
		return ;
	else if (a && isNextNull)
	{
		rrb(s);
		pa(a, s);
		rrb(s);
		pa(a, s);
		pa(a, s);
	}
	else if (a && !isNextNull)
	{
		rb(s);
		sb(s);
		pa(a, s);
		pa(a, s);
		rrb(s);
		pa(a, s);
	}
}

void	core_operations_3_nodes_132(t_stack *a, t_stack *s, int isNextNull)
{
	if (!a && isNextNull)
	{
		rra(s);
		sa(s);
	}
	else if (!a && !isNextNull)
	{
		ra(s);
		sa(s);
		rra(s);
	}
	else if (a)
	{
		rb(s);
		pa(a, s);
		pa(a, s);
		if (!isNextNull)
			rrb(s);
		pa(a, s);
	}
}

void	core_operations_3_nodes_213(t_stack *a, t_stack *s, int isNextNull)
{
	if (!a && isNextNull)
		sa(s);
	else if (!a && !isNextNull)
		sa(s);
	else if (a && isNextNull)
	{
		rrb(s);
		pa(a, s);
		pa(a, s);
		pa(a, s);
	}
	else if (a && !isNextNull)
	{
		rb(s);
		sb(s);
		pa(a, s);
		rrb(s);
		pa(a, s);
		pa(a, s);
	}
}

void	core_operations_3_nodes_231(t_stack *a, t_stack *s, int isNextNull)
{
	if (!a && isNextNull)
		rra(s);
	else if (!a && !isNextNull)
	{
		ra(s);
		sa(s);
		rra(s);
		sa(s);
	}
	else if (a && isNextNull)
	{
		sb(s);
		pa(a, s);
		pa(a, s);
		pa(a, s);
	}
	else if (a && !isNextNull)
	{
		sb(s);
		pa(a, s);
		pa(a, s);
		pa(a, s);
	}
}

void	core_operations_3_nodes_312(t_stack *a, t_stack *s, int isNextNull)
{
	if (!a && isNextNull)
		ra(s);
	else if (!a && !isNextNull)
	{	
		sa(s);
		ra(s);
		sa(s);
		rra(s);
	}
	else if (a && isNextNull)
	{
		pa(a, s);
		sb(s);
		pa(a, s);
		pa(a, s);
	}
	else if (a && !isNextNull)
	{
		pa(a, s);
		sb(s);
		pa(a, s);
		pa(a, s);
	}
}
