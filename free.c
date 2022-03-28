/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:44:26 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/10 16:44:26 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_a(t_list *stack)
{
	t_node	*delete;

	if (stack->stack_a != NULL)
	{
		while (stack->stack_a->next != NULL)
		{
			delete = stack->stack_a;
			stack->stack_a = stack->stack_a->next;
			stack->stack_a->prev = NULL;
			free(delete);
		}
		free(stack->stack_a);
	}
}

void	free_stack_b(t_list *stack)
{
	t_node	*delete;

	if (stack->stack_b != NULL)
	{
		while (stack->stack_b->next != NULL)
		{
			delete = stack->stack_b;
			stack->stack_b = stack->stack_b->next;
			stack->stack_b->prev = NULL;
			free(delete);
		}
		free(stack->stack_b);
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_list *stack)
{
	free_stack_a(stack);
	free_stack_b(stack);
	free(stack);
}
