# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 12:34:52 by ebellon           #+#    #+#              #
#    Updated: 2021/03/28 17:02:12 by ebellon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= cub3d
FILES			=	data_file_parsing/parsing_3d_map.c \
					data_file_parsing/parsing1.c \
					shutdown/ft_shutdown.c \
					draw_ray/ray.c

INC_FILES		= cub3d.h
INC_PATH		= ./Headers/
INC				= $(addprefix ${INC_PATH}, ${INC_FILES})
SRC_PATH		= ./Srcs/
SRC				= $(addprefix ${SRC_PATH}, ${FILES})

CC				= gcc
OBJS			= ${SRC:.c=.o}
FLAGS			= -Wall -Wextra -Werror -O3

#LIBRARY
NAME_LIBFT		= libft.a
LIBFT_PATH		= libft/
LIBFT			= $(addprefix ${LIBFT_PATH}, ${NAME_LIBFT})
NAME_MINILIBX	= libmlx.dylib
MINILIBX_PATH	= minilibx/
MINILIBX		= $(addprefix ${MINILIBX_PATH}, ${NAME_MINILIBX})

all:			${NAME}

lib:
				make -C ${LIBFT_PATH}
				make -C ${MINILIBX_PATH}
				cp ${LIBFT} .
				cp ${MINILIBX} .

%.o: %.c		${INC}
				${CC} ${FLAGS} -c $< -o $@ -I ${INC_PATH}

${NAME}:		lib ${OBJS}
				${CC} ${OBJS} main.c -o ${NAME} ${NAME_LIBFT} ${NAME_MINILIBX} -I ${INC_PATH}

clean:
				make -C ${LIBFT_PATH} clean
				make -C ${MINILIBX_PATH} clean
				${RM} ${OBJS} ${OBJS_BONUS}
				${RM} cub3d.bmp

fclean:			clean
				${RM} ${NAME}
				${RM} ${LIBFT}
				${RM} ${NAME_LIBFT}
				${RM} ${NAME_MINILIBX}
				${RM} ${MINILIBX}

re:				fclean all


.PHONY: all clean fclean re bonus lib test