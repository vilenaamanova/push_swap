/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:56:18 by ncathy            #+#    #+#             */
/*   Updated: 2022/02/16 19:56:18 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bottom_a(t_list *stack)
{
	t_node	*tmp;
	int		bottom;
	int		size_of_chunk;

	tmp = stack->stack_a;
	size_of_chunk = stack->size_of_a;
	while (tmp && size_of_chunk > 0)
	{
		bottom = tmp->data;
		tmp = tmp->next;
		size_of_chunk--;
	}
	return (bottom);
}

int	*create_arr(int nbr_element)
{
	int	n;
	int	*arr;

	n = find_arr_size(nbr_element);
	arr = (int *)malloc(sizeof(int) * n + 2);
	if (!arr)
		exit(1);
	return (arr);
}

int	find_arr_size(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 2;
		i++;
	}
	return (i);
}

int	my_power(int n)
{
	int	i;
	int	nbr;

	nbr = 1;
	i = 0;
	while (++i < n)
	{
		nbr = nbr * 2;
	}
	return (nbr);
}

int	check_nbr(t_list *stack)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = stack->stack_a;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
