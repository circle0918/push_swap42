/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:42:04 by yyuan             #+#    #+#             */
/*   Updated: 2021/10/31 02:45:58 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
#include "../push_swap.h" 

static int	is_digit(char *s)
{
	char	*p;

	p = s;
	while (*p != '\0')
	{
		if (!(ft_isdigit(*p) || *p == '+' || *p == '-'))
			return (0);
		p++;
	}
	return (1);
}

static int	is_int_range(char *s)
{
	long long	d;

	d = ft_atoll(s);
	if (d > (long long)(2147483647) || d < (long long)(-2147483648))
		return (0);
	return (1);
}

static int	is_str_int(char *s)
{
	if (!is_digit(s))
		return (0);
	if (!is_int_range(s))
		return (0);
	return (1);
}

static int	is_duplicated(t_stack *a, int data)
{
	t_node	*n;

	n = a->top;
	while (n)
	{
		if (n->data == data)
			return (1);
		n = n->next;
	}
	return (0);
}

int	push_args_safely(t_stack *a, int ac, char **av)
{
	int		i;
	int		data;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = av[ac - i];
		if (!is_str_int(str))
			return (0);
		data = ft_atoi(str);
		if (is_duplicated(a, data))
			return (0);
		stack_push(a, data);
		i++;
	}
	return (1);
}
