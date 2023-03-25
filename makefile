# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 15:52:59 by daparici          #+#    #+#              #
#    Updated: 2023/03/25 20:13:09 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_Swap
CC = gcc 
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address -g3
AR = ar rcs

SRC = main.c

OBJS = ${SRC:.c=.o}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${MAKE} -C ./printf
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a ./printf/libftprintf.a -o ${NAME}

all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME) 
re: clean all
.PHONY: bonus all clean fclean re
