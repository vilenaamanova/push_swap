/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:06:11 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/12 21:06:11 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(char **argv)
{
	int		i;
	char	**nums;
	t_list	*stack;

	i = 0;
	nums = get_array_of_args(argv);
	while (nums[i])
		i++;
	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		exit(1);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->size_of_a = i;
	stack->size_of_b = 0;
	free_array(nums);
	return (stack);
}

void	fill_the_stack_a(t_list *stack, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	args = get_array_of_args(argv);
	while (i < stack->size_of_a)
	{
		push_to_the_end_a(stack, ft_atoi(args[i]));
		i++;
	}
	free_array(args);
}
