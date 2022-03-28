/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:10:27 by ncathy            #+#    #+#             */
/*   Updated: 2022/02/03 16:10:27 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list *stack)
{
	int	move_data;

	if (stack->stack_a != NULL)
	{
		move_data = stack->stack_a->data;
		pop_from_the_front_a(stack);
		push_to_the_end_a(stack, move_data);
	}
}

void	rotate_b(t_list *stack)
{
	int	move_data;

	if (stack->stack_b != NULL)
	{
		move_data = stack->stack_b->data;
		pop_from_the_front_b(stack);
		push_to_the_end_b(stack, move_data);
	}
}

void	ra(t_list *stack)
{
	rotate_a(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list *stack)
{
	rotate_b(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
}
