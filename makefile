# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 15:52:59 by daparici          #+#    #+#              #
#    Updated: 2023/05/23 18:46:30 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc 
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address -g3
AR = ar rcs
LIB = ./Libft/libft.a
SRC = main.c utils.c movements.c checker_imput.c sort_list.c

OBJS = ${SRC:.c=.o}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${MAKE} -C ./printf
	@${CC} ${CFLAGS} ${OBJS} ${LIB} ./printf/libftprintf.a -o ${NAME}

all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
	make fclean -C ./Libft;
	make fclean -C ./printf;
re: clean all
.PHONY: bonus all clean fclean re
