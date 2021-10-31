/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:35:12 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/29 19:44:27 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	stack_init(a);
	b = (t_stack *)malloc(sizeof(t_stack));
	stack_init(b);
	if (!push_args_safely(a, ac, av))
	{
		write(1, "Error\n", 6);
		stack_free(a);
		return (0);
	}
	core_process(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
