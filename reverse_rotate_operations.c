/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:22:39 by ncathy            #+#    #+#             */
/*   Updated: 2022/02/04 19:22:39 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list *stack)
{
	t_node	*last_node;
	int		move_data;

	if (stack->stack_a != NULL)
	{
		last_node = stack->stack_a;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = NULL;
		move_data = last_node->data;
		pop_from_the_end_a(stack);
		push_to_the_front_a(stack, move_data);
	}
}

void	reverse_rotate_b(t_list *stack)
{
	t_node	*last_node;
	int		move_data;

	if (stack->stack_b != NULL)
	{
		last_node = stack->stack_b;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = NULL;
		move_data = last_node->data;
		pop_from_the_end_b(stack);
		push_to_the_front_b(stack, move_data);
	}
}

void	rra(t_list *stack)
{
	reverse_rotate_a(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list *stack)
{
	reverse_rotate_b(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	write(1, "rrr\n", 4);
}
