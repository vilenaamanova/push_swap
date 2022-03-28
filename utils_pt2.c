/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:55:40 by ncathy            #+#    #+#             */
/*   Updated: 2022/02/09 14:55:40 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_a_position(t_list *stack)
{
	t_node	*tmp;
	int		pos_num;

	tmp = stack->stack_a;
	pos_num = 0;
	find_min_max_mid_a(stack, stack->size_of_a);
	while (tmp->data != stack->min_a)
	{
		tmp = tmp->next;
		pos_num++;
	}
	stack->pos_min_a = pos_num;
}

void	move_to_the_top_min_a(t_list *stack)
{
	find_min_a_position(stack);
	if (stack->pos_min_a < (stack->size_of_a / 2))
	{
		while (stack->stack_a->data != stack->min_a)
			ra(stack);
	}
	else if (stack->pos_min_a >= (stack->size_of_a / 2))
	{
		while (stack->stack_a->data != stack->min_a)
			rra(stack);
	}
}

void	find_min_max_mid_b(t_list *stack, int size_of_chunk)
{
	t_node	*tmp;
	int		mid;
	int		i;

	i = 0;
	tmp = stack->stack_b;
	stack->min_b = tmp->data;
	stack->max_b = tmp->data;
	while (i < size_of_chunk)
	{
		if (stack->min_b > tmp->data)
			stack->min_b = tmp->data;
		if (stack->max_b < tmp->data)
			stack->max_b = tmp->data;
		tmp = tmp->next;
		i++;
	}
	mid = (stack->min_b + stack->max_b);
	if (mid % 2 == 0)
		stack->mid_val_b = (mid / 2);
	else if ((mid % 2 == 1) || (mid % 2 == -1))
		stack->mid_val_b = ((mid - 1) / 2);
}

int	is_sorted_pt2(t_list *stack)
{
	t_node	*tmp;

	tmp = stack->stack_a;
	while (tmp->next != NULL && (tmp->data < tmp->next->data))
	{
		tmp = tmp->next;
	}
	if (tmp->next != NULL)
		return (1);
	return (0);
}

void	sort_stack_b(t_list *stack)
{
	if (stack->stack_b->data < stack->stack_b->next->data)
		sb(stack);
}
