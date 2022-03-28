/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_pt2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:37:11 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/11 09:37:11 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_and_sort_chunks(t_list *stack, int size_of_chunk)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * count_arr(size_of_chunk));
	if (!arr)
		exit(1);
	if (size_of_chunk == 1 || size_of_chunk == 2)
		move_small_chunk(stack, size_of_chunk);
	else if (size_of_chunk > 2)
		move_big_chunk(stack, arr, size_of_chunk);
	free(arr);
}

void	move_big_chunk(t_list *stack, int *arr, int size_of_chunk)
{
	int	i;
	int	size_of_chunk_a;

	i = 1;
	push_elems_to_a(stack, size_of_chunk);
	size_of_chunk_a = size_of_chunk / 2;
	arr[0] = size_of_chunk - size_of_chunk_a;
	while (size_of_chunk_a > 2)
	{
		arr[i] = from_a_to_b(stack, size_of_chunk_a);
		size_of_chunk_a = get_chunk_a_size(size_of_chunk_a);
		i++;
	}
	if (stack->stack_a->data > stack->stack_a->next->data)
		sa(stack);
	i = count_arr(size_of_chunk) - 1;
	while (i >= 0)
		move_and_sort_chunks(stack, arr[i--]);
}

void	move_small_chunk(t_list *stack, int size_of_chunk)
{
	int	k;

	k = 0;
	if (size_of_chunk == 1)
		pa(stack);
	else if (size_of_chunk == 2)
	{
		k = 0;
		if (stack->stack_b->data < stack->stack_b->next->data)
			sb(stack);
		while (k < size_of_chunk)
		{
			pa(stack);
			k++;
		}
	}
}

int	get_chunk_a_size(int size_of_chunk_a)
{
	if (size_of_chunk_a % 2 == 1)
		size_of_chunk_a = size_of_chunk_a / 2 + 1;
	else if (size_of_chunk_a % 2 == 0)
		size_of_chunk_a = size_of_chunk_a / 2;
	return (size_of_chunk_a);
}

void	move_elems_back(t_list *stack, int i)
{
	while (i > 0)
	{
		rra(stack);
		i--;
	}
}
