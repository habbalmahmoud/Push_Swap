SRCS = main.c parse.c push.c swap.c rotate.c r_rotate.c sort.c push_swap_utils.c true_indicies.c radix.c

SRCS_DIR = $(addprefix srcs/, $(SRCS))

OBJS = ${SRCS_DIR:.c=.o}

NAME = push_swap

LIBFT = Libft/libft.a

PRINT_F = Printf/libftprintf.a

CC = cc
C_FLAGS = -Wall -Wextra -Werror -g
RM = rm -f

all : $(NAME)

.c.o :
		${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}


$(NAME) : ${LIBFT} ${PRINT_F} ${OBJS}
		  ${CC} ${C_FLAGS} ${OBJS} ${LIBFT} ${PRINT_F} -o ${NAME}

$(LIBFT) :
		  @make -C ./Libft

$(PRINT_F) :
			@make -C ./Printf

clean :	
		@make clean -C ./Libft
		@make clean -C ./Printf
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME} ${LIBFT} ${PRINT_F}

re : fclean all

.PHONY : all clean fclean re