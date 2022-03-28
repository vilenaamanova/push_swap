/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:04:16 by ncathy            #+#    #+#             */
/*   Updated: 2022/02/03 16:04:16 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *stack)
{
	if (stack->stack_a != NULL && stack->stack_a->next != NULL)
		swap(&stack->stack_a->data, &stack->stack_a->next->data);
}

void	swap_b(t_list *stack)
{
	if (stack->stack_b != NULL && stack->stack_b->next != NULL)
		swap(&stack->stack_b->data, &stack->stack_b->next->data);
}

void	sa(t_list *stack)
{
	swap_a(stack);
	write(1, "sa\n", 3);
}

void	sb(t_list *stack)
{
	swap_b(stack);
	write(1, "sb\n", 3);
}

void	ss(t_list *stack)
{
	swap_a(stack);
	swap_b(stack);
	write(1, "ss\n", 3);
}
