# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 14:31:46 by rihoy             #+#    #+#              #
#    Updated: 2023/11/20 12:01:13 by rihoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_char.c ft_hexa.c ft_print_digit.c ft_utils.c \

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra -I
CC = cc
RM = rm -f
NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean :
	${RM} ${OBJS}

fclean :
	${RM} ${NAME}

re : fclean ${NAME}