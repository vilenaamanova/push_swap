/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_A_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:46:02 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/31 13:46:02 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_the_front_a(t_list *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = stack->stack_a;
	if (stack->stack_a != NULL)
		stack->stack_a->prev = new_node;
	stack->stack_a = new_node;
}

void	push_to_the_end_a(t_list *stack, int data)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	last_node = stack->stack_a;
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;
	if (stack->stack_a == NULL)
		stack->stack_a = new_node;
	else
	{
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
		last_node = new_node;
	}
}

void	pop_from_the_front_a(t_list *stack)
{
	t_node	*delete;

	if (stack->stack_a == NULL)
		exit(1);
	else
	{
		if (stack->stack_a->next == NULL)
		{
			free(stack->stack_a);
			stack->stack_a = NULL;
		}
		else
		{
			delete = stack->stack_a;
			stack->stack_a = stack->stack_a->next;
			stack->stack_a->prev = NULL;
			free(delete);
		}
	}
}

void	pop_from_the_end_a(t_list *stack)
{
	t_node	*prev_node;
	t_node	*tmp;

	tmp = stack->stack_a;
	if (stack->stack_a == NULL)
		exit(1);
	else
	{
		if (stack->stack_a->next == NULL)
		{
			free(stack->stack_a);
			stack->stack_a = NULL;
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
