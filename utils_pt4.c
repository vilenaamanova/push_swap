/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:35:19 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/11 09:35:19 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nbr_b(t_list *stack)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = stack->stack_b;
	while (tmp->next != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	count_arr(int size_of_chunk)
{
	int	count;
	int	half_num;

	count = 1;
	half_num = size_of_chunk / 2;
	while (half_num > 2)
	{
		half_num = half_num - half_num / 2;
		count++;
	}
	return (count);
}

int	arr_length(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}
