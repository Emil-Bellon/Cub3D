# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 12:34:52 by ebellon           #+#    #+#              #
#    Updated: 2021/05/27 17:41:14 by ebellon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= cub3d
FILES			=	error_management/ft_error.c \
					keys/key_event.c \
					parsing/parse_data.c \
					parsing/parse_nbr.c \
					parsing/parse_txtr.c \
					parsing/parse_tool.c \
					parsing/check_data.c \
					game_actions/player_move.c \
					game_actions/player_move2.c \
					display/ray_cast.c \
					display/draw_txtr.c \
					display/draw_sprite.c \
					display/trip.c \
					display/sprite_utils.c \
					display/display_utils.c

INC_FILES		= cub3d.h
INC_PATH		= ./Headers/
INC				= $(addprefix ${INC_PATH}, ${INC_FILES})
SRC_PATH		= ./Srcs/
SRC				= $(addprefix ${SRC_PATH}, ${FILES})

CC				= gcc
OBJS			= ${SRC:.c=.o}
FLAGS			= -Wall -Wextra -Werror

#LIBRARY
NAME_LIBFT		= libft.a
LIBFT_PATH		= libft/
LIBFT			= $(addprefix ${LIBFT_PATH}, ${NAME_LIBFT})
NAME_MINILIBX	= libmlx.dylib
MINILIBX_PATH	= minilibx/
MINILIBX		= $(addprefix ${MINILIBX_PATH}, ${NAME_MINILIBX})

all:			${NAME}

# linking
${NAME}:		lib ${OBJS}
				${CC} ${OBJS} main.c -o ${NAME} ${NAME_LIBFT} ${NAME_MINILIBX} -I ${INC_PATH} $(FLAGS)

%.o: %.c		${INC}
				${CC} -c $< -o $@ -I ${INC_PATH} ${FLAGS}

# source compilation
lib:
				make -C ${LIBFT_PATH}
				make -C ${MINILIBX_PATH}
				cp ${LIBFT} .
				cp ${MINILIBX} .


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