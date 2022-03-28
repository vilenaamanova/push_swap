/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:42:00 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/26 14:48:17 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_list *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	double_rotate(t_list *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void	double_reverse_rotate(t_list *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}
