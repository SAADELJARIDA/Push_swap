# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 02:57:14 by sel-jari          #+#    #+#              #
#    Updated: 2025/04/11 02:57:16 by sel-jari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ab_ops.c b_ops.c init.c normalize_input.c push_swap.c stack_ops.c \
	a_ops.c free_and_exit.c quick_sort.c parse_args.c small_sorts.c big_sort.c

NAME = push_swap

OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wall -Werror

LIBFT = libft/libft.a

RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} ${LIBFT} -o ${NAME}

clean:
	${RM} ${OBJ}
fclean:
	${RM} ${NAME} ${OBJ}
re: fclean all
