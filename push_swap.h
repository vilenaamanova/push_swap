/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:34:26 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/10 15:34:26 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFFER_SIZE 4

typedef struct s_node {
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list {
	struct s_node	*stack_a;
	struct s_node	*stack_b;
	int				size_of_a;
	int				size_of_b;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	int				pos_min_a;
	int				pos_min_b;
	int				mid_val_a;
	int				mid_val_b;
	int				size_of_chunk;
}	t_list;

/* get_next_line */
char	*get_next_line(int fd);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

/* argument handling */
char	**get_array_of_args(char **argv);
int		check_isdigit(char **argv);
int		check_for_dublicates(char **argv);
int		check_the_value(char **argv);

/* stack handling */
t_list	*init_stack(char **argv);
void	fill_the_stack_a(t_list *stack, char **argv);
void	define_stack(t_list *stack);
int		is_sorted(t_list *stack);
void	find_min_max_mid_a(t_list *stack, int num);
void	find_min_max_mid_b(t_list *stack, int size_of_chunk);
void	find_min_a_position(t_list *stack);
void	move_to_the_top_min_a(t_list *stack);
void	push_to_the_front_a(t_list *stack, int data);
void	push_to_the_end_a(t_list *stack, int data);
void	pop_from_the_front_a(t_list *stack);
void	pop_from_the_end_a(t_list *stack);
void	push_to_the_front_b(t_list *stack, int data);
void	push_to_the_end_b(t_list *stack, int data);
void	pop_from_the_front_b(t_list *stack);
void	pop_from_the_end_b(t_list *stack);
void	free_stack_a(t_list *stack);
void	free_stack_b(t_list *stack);
void	free_array(char **arr);
void	free_all(t_list *stack);

/* swap operations */
void	swap(int *a, int *b);
void	swap_a(t_list *stack);
void	swap_b(t_list *stack);

/* push operations */
void	push_a(t_list *stack);
void	push_b(t_list *stack);

/* rotate operations */
void	rotate_a(t_list *stack);
void	rotate_b(t_list *stack);
void	reverse_rotate_a(t_list *stack);
void	reverse_rotate_b(t_list *stack);

/* push_swap operations */
void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *stack);
void	pa(t_list *stack);
void	pb(t_list *stack);
void	ra(t_list *stack);
void	rb(t_list *stack);
void	rr(t_list *stack);
void	rra(t_list *stack);
void	rrb(t_list *stack);
void	rrr(t_list *stack);

/* sort small stack */
int		stack_of_two(t_list *stack);
int		stack_of_three(t_list *stack);
int		stack_of_five(t_list *stack);

/* sort big stack */
int		find_bottom_a(t_list *stack);
void	move_and_sort_chunks(t_list *stack, int size_of_chunk);
void	sort_stack_b(t_list *stack);
int		is_sorted_pt2(t_list *stack);
int		push_elems_to_b(t_list *stack);
void	push_elems_to_a(t_list *stack, int size_of_chunk);
void	big_stack(t_list *stack);
int		from_a_to_b(t_list *stack, int size_of_chunk);
void	from_b_to_a(t_list *stack, int *arr);
void	move_small_chunk(t_list *stack, int size_of_chunk);
int		get_chunk_a_size(int size_of_chunk_a);
void	move_elems_back(t_list *stack, int i);
void	move_big_chunk(t_list *stack, int *arr, int size_of_chunk);

int		*create_arr(int nbr_element);
int		find_arr_size(int n);
int		my_power(int n);
int		check_nbr(t_list *stack);
int		check_nbr_b(t_list *stack);
int		count_arr(int size_of_chunk);
int		arr_length(int *arr);

/* checker */
void	cmp_operations(t_list *stack, char *operation);
void	get_and_cmp(t_list *stack);
int		is_sorted_checker(t_list *stack);
void	double_swap(t_list *stack);
void	double_rotate(t_list *stack);
void	double_reverse_rotate(t_list *stack);
void	error_exit(char *operation);

/* main function */
int		main(int argc, char **argv);

#	endif
