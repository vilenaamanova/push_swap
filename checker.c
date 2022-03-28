/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:24:25 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/12 16:24:25 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmp_operations(t_list *stack, char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		swap_a(stack);
	else if (!ft_strncmp(operation, "sb\n", 3))
		swap_b(stack);
	else if (!ft_strncmp(operation, "ss\n", 3))
		double_swap(stack);
	else if (!ft_strncmp(operation, "pa\n", 3))
		push_a(stack);
	else if (!ft_strncmp(operation, "pb\n", 3))
		push_b(stack);
	else if (!ft_strncmp(operation, "ra\n", 3))
		rotate_a(stack);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rotate_b(stack);
	else if (!ft_strncmp(operation, "rr\n", 3))
		double_rotate(stack);
	else if (!ft_strncmp(operation, "rra\n", 4))
		reverse_rotate_a(stack);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		reverse_rotate_b(stack);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		double_reverse_rotate(stack);
	else
		error_exit(operation);
}

void	error_exit(char *operation)
{
	free(operation);
	write(1, "Error\n", 6);
	exit(1);
}

void	get_and_cmp(t_list *stack)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		cmp_operations(stack, operation);
		free(operation);
		operation = get_next_line(0);
	}
	free(operation);
}

int	is_sorted_checker(t_list *stack)
{
	t_node	*tmp;

	tmp = stack->stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	if (argc > 1)
	{
		check_the_value(argv);
		stack = init_stack(argv);
		fill_the_stack_a(stack, argv);
		if (stack->size_of_a == 1)
			return (0);
		get_and_cmp(stack);
		if (is_sorted_checker(stack) == 0 && stack->stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stack_a(stack);
		free_stack_b(stack);
		free(stack);
	}
	return (0);
}
