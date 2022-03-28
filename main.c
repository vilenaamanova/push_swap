/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:32:02 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/24 16:32:02 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;

	if (argc > 1)
	{
		check_the_value(argv);
		stack = init_stack(argv);
		fill_the_stack_a(stack, argv);
		is_sorted(stack);
		free_stack_a(stack);
		free_stack_b(stack);
		free(stack);
	}
	return (0);
}
