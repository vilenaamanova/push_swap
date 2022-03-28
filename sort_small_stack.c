/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:28:10 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/24 17:28:10 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_of_two(t_list *stack)
{
	int	a;
	int	b;

	a = stack->stack_a->data;
	b = stack->stack_a->next->data;
	if (a > b)
		sa(stack);
	return (0);
}

int	stack_of_three(t_list *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->stack_a->data;
	b = stack->stack_a->next->data;
	c = stack->stack_a->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack);
	if (a > b && b > c && a > c)
	{
		sa(stack);
		rra(stack);
	}
	if (a > b && b < c && a > c)
		ra(stack);
	if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	if (a < b && b > c && a > c)
		rra(stack);
	return (0);
}

int	stack_of_five(t_list *stack)
{
	while (stack->size_of_a != 3)
	{
		move_to_the_top_min_a(stack);
		pb(stack);
	}
	stack_of_three(stack);
	while (stack->stack_b != NULL)
		pa(stack);
	return (0);
}
