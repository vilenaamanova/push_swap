/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:28:20 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/24 17:28:20 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_elems_to_b(t_list *stack)
{
	int	num;
	int	bottom;
	int	half_num;

	num = 0;
	find_min_max_mid_a(stack, stack->size_of_a);
	half_num = (stack->size_of_a / 2);
	while (num < half_num)
	{
		bottom = find_bottom_a(stack);
		if (stack->stack_a->data < stack->mid_val_a)
		{
			pb(stack);
			num++;
		}
		else if (bottom < stack->mid_val_a)
		{
			rra(stack);
			pb(stack);
			num++;
		}
		else
			ra(stack);
	}
	return (num);
}

void	from_b_to_a(t_list *stack, int *arr)
{
	int	n;
	int	length;

	n = 0;
	length = arr_length(arr) - 1;
	while (length >= 0)
	{
		if (arr[length] == 1)
			pa(stack);
		else
		{
			n = arr[length];
			move_and_sort_chunks(stack, n);
		}
		length--;
	}
}

void	push_elems_to_a(t_list *stack, int size_of_chunk)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_min_max_mid_b(stack, size_of_chunk);
	while (j < size_of_chunk)
	{
		if (stack->stack_b->data > stack->mid_val_b)
			pa(stack);
		else
		{
			rb(stack);
			i++;
		}
		j++;
	}
	while (i > 0)
	{
		rrb(stack);
		i--;
	}
}

int	from_a_to_b(t_list *stack, int size_of_chunk)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	num = 0;
	find_min_max_mid_a(stack, size_of_chunk);
	while (j < size_of_chunk)
	{
		if (stack->stack_a->data < stack->mid_val_a)
		{
			pb(stack);
			num++;
		}
		else
		{
			ra(stack);
			i++;
		}
		j++;
	}
	move_elems_back(stack, i);
	return (num);
}

void	big_stack(t_list *stack)
{
	int	i;
	int	n;
	int	*arr;

	i = 0;
	n = find_arr_size(check_nbr(stack));
	arr = (int *)malloc(sizeof(int) * n + 1);
	if (!arr)
		exit(1);
	while (stack->size_of_a > 3)
	{
		arr[i] = push_elems_to_b(stack);
		i++;
	}
	arr[i] = '\0';
	if (is_sorted_pt2(stack) == 1)
		is_sorted(stack);
	from_b_to_a(stack, arr);
	free(arr);
}
