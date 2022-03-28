/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_B_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:45:47 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/31 13:45:47 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_the_front_b(t_list *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = stack->stack_b;
	if (stack->stack_b != NULL)
		stack->stack_b->prev = new_node;
	stack->stack_b = new_node;
}

void	push_to_the_end_b(t_list *stack, int data)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	last_node = stack->stack_b;
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;
	if (stack->stack_b == NULL)
		stack->stack_b = new_node;
	else
	{
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
		last_node = new_node;
	}
}

void	pop_from_the_front_b(t_list *stack)
{
	t_node	*delete;

	if (stack->stack_b == NULL)
		exit(1);
	else
	{
		if (stack->stack_b->next == NULL)
		{
			free(stack->stack_b);
			stack->stack_b = NULL;
		}
		else
		{
			delete = stack->stack_b;
			stack->stack_b = stack->stack_b->next;
			free(delete);
			stack->stack_b->prev = NULL;
		}
	}
}

void	pop_from_the_end_b(t_list *stack)
{
	t_node	*prev_node;
	t_node	*tmp;

	tmp = stack->stack_b;
	if (stack->stack_b == NULL)
		exit(1);
	else
	{
		if (stack->stack_b->next == NULL)
		{
			free(stack->stack_b);
			stack->stack_b = NULL;
		}
		else
		{
			while (tmp->next != NULL)
			{
				prev_node = tmp;
				tmp = tmp->next;
			}
			free(tmp);
			prev_node->next = NULL;
		}
	}
}
