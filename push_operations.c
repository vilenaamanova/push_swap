/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:52:40 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/26 12:52:40 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list *stack)
{
	int	move_data;

	if (stack->stack_b != NULL)
	{
		move_data = stack->stack_b->data;
		push_to_the_front_a(stack, move_data);
		pop_from_the_front_b(stack);
		stack->size_of_b--;
		stack->size_of_a++;
	}
}

void	push_b(t_list *stack)
{
	int	move_data;

	if (stack->stack_a != NULL)
	{
		move_data = stack->stack_a->data;
		push_to_the_front_b(stack, move_data);
		pop_from_the_front_a(stack);
		stack->size_of_b++;
		stack->size_of_a--;
	}
}

void	pa(t_list *stack)
{
	push_a(stack);
	write(1, "pa\n", 3);
}

void	pb(t_list *stack)
{
	push_b(stack);
	write(1, "pb\n", 3);
}
