/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:29:40 by ncathy            #+#    #+#             */
/*   Updated: 2022/02/03 16:29:40 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_stack(t_list *stack)
{
	if (stack->size_of_a == 2)
		stack_of_two(stack);
	else if (stack->size_of_a == 3)
		stack_of_three(stack);
	else if (stack->size_of_a == 4 || stack->size_of_a == 5)
		stack_of_five(stack);
	else if (stack->size_of_a > 5)
		big_stack(stack);
}

int	is_sorted(t_list *stack)
{
	t_node	*tmp;

	tmp = stack->stack_a;
	if (stack->size_of_a == 1)
		return (0);
	while (tmp->next != NULL && (tmp->data < tmp->next->data))
		tmp = tmp->next;
	if (tmp->next == NULL)
	{
		free_stack_a(stack);
		free(stack);
		exit(1);
	}
	else
		define_stack(stack);
	return (0);
}

void	find_min_max_mid_a(t_list *stack, int num)
{
	t_node	*tmp;
	int		mid;
	int		i;

	i = 0;
	tmp = stack->stack_a;
	stack->min_a = tmp->data;
	stack->max_a = tmp->data;
	while (i < num)
	{
		if (stack->min_a > tmp->data)
			stack->min_a = tmp->data;
		if (stack->max_a < tmp->data)
			stack->max_a = tmp->data;
		tmp = tmp->next;
		i++;
	}
	mid = (stack->min_a + stack->max_a);
	if (mid % 2 == 0)
		stack->mid_val_a = (mid / 2);
	else if ((mid % 2 == 1) || (mid % 2 == -1))
		stack->mid_val_a = ((mid + 1) / 2);
}
