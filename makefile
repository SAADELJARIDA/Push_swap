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
	a_ops.c free_and_exit.c quick_sort.c parse_args.c small_sorts.c big_sort.c \
	push_to_a.c

NAME = push_swap
HEADER = push_swap.h
OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wall -Werror -g

LIB_DIR = libft
LIB_FILE = libft.a
LIB = $(LIB_DIR)/$(LIB_FILE)

RM = rm -f

all: ${NAME}

${NAME}: ${OBJ} ${HEADER} ${LIB}
	${CC} ${OBJ} ${LIB} -o ${NAME}

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	${RM} ${OBJ}
	$(MAKE) clean -C $(LIB_DIR)
fclean:
	${RM} ${NAME} ${OBJ}
	$(MAKE) fclean -C $(LIB_DIR)
re: fclean all
