NAME	=	push_swap

NAME_BONUS	=	checker

SRCS	=	free.c \
			init.c \
			main.c \
			parse_arguments.c \
			push_operations.c \
			reverse_rotate_operations.c \
			rotate_operations.c \
			sort_big_stack.c \
			sort_big_stack_pt2.c \
			sort_small_stack.c \
			stack_A_handling.c \
			stack_B_handling.c \
			swap_operations.c \
			swap.c \
			utils.c \
			utils_pt2.c \
			utils_pt3.c \
			utils_pt4.c

SRCS_BONUS	=	./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c \
				free.c \
				init.c \
				parse_arguments.c \
				push_operations.c \
				reverse_rotate_operations.c \
				rotate_operations.c \
				swap_operations.c \
				swap.c \
				stack_A_handling.c \
				stack_B_handling.c \
				checker.c \
				checker_utils.c

LIBFT	=	./libft/libft.a

HEADER	=	push_swap.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

OBJ_BONUS	=	$(patsubst %.c, %.o, $(SRCS_BONUS))

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all 	:	$(NAME)

$(NAME)	: 	$(OBJ) $(HEADER)
			@$(MAKE) -C ./libft --silent
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_BONUS)	:	$(OBJ_BONUS) $(HEADER)
					@$(MAKE) -C ./libft --silent
					$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

%.o	: %.c	$(HEADER)
	$(CC)	$(CFLAGS) -c $< -o $@

bonus	:	checker

clean	:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)
	@$(MAKE) clean -C ./libft

fclean	:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@$(MAKE) fclean -C ./libft

re		:	fclean all
