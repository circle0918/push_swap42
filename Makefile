CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar cr
NAME= push_swap
SOURCES = ./main.c \
			./0_push_args/push_args.c ./0_push_args/ft_adoll.c \
			./1_core_process/core.c ./1_core_process/core_3_nodes_1.c ./1_core_process/core_3_nodes_2.c \
			./1_core_process/core_3_nodes_3.c ./1_core_process/core_a2b.c ./1_core_process/core_b2a.c \
			./2_optimize/optim_a2b.c ./2_optimize/optim_utils_1.c ./2_optimize/optim_utils_2.c \
			./3_utils_stacK/stack_1.c ./3_utils_stacK/stack_2.c ./3_utils_stacK/stack_3.c ./3_utils_stacK/stack_4.c ./3_utils_stacK/stack_5.c \
			./4_utils_operations/operation_p.c ./4_utils_operations/operation_s.c ./4_utils_operations/operation_r.c \
			./4_utils_operations/operation_rr.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

#TODO
#$(NAME): LIB $(OBJECTS)
#	$(CC) $(CFLAGS) $(OBJECTS) libft.a -o $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -L. -lft -o $(NAME)

#LIB:
#	make -C ./libft
#	cp ./libft/libft.a libft.a

clean:
	$(RM) $(OBJECTS)
#	make clean -C ./libft

#removes all *.o files + libft.a + libmlx.a
fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJECTS)
#	$(RM) ./libft/libft.a
#	$(RM) libft.a

#removes all *.o files + libft.a + libmlx.a and rebuild everything
re: fclean all
