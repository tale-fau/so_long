# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 11:35:40 by tale-fau          #+#    #+#              #
#    Updated: 2021/08/19 15:41:17 by tale-fau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------

RED = \033[0;91m
GREEN = \033[0;92m
BLUE = \033[0;34m
WHITE = \x1b[0m
YELLOW = \x1b[33;01m

# ------------------------------------------------------------------------------


# ------------------------------------------------------------------------------

SRCS			=	srcs/main.c \
						srcs/Error_Management/errors.c \
						srcs/Free/free_all.c \
						srcs/Initializing/initialize.c \
						srcs/Manage_exit/exit_game.c \
						srcs/Manage_exit/victory.c \
						srcs/Movement/key_manager.c \
						srcs/Movement/moves.c \
						srcs/Parsing/is_map_valid.c \
						srcs/Parsing/parse_args.c \
						srcs/Parsing/parse_map.c \
						srcs/Render/drawing.c \
						srcs/Render/pixel_put.c \
						srcs/Render/textures_loading.c

SRCS_BONUS		=	bonus/srcs/main.c \
						bonus/srcs/Error_Management/errors.c \
						bonus/srcs/Free/free_all.c \
						bonus/srcs/Initializing/initialize.c \
						bonus/srcs/Initializing/number_init.c \
						bonus/srcs/Initializing/enemy_init.c \
						bonus/srcs/Manage_exit/exit_game.c \
						bonus/srcs/Manage_exit/victory.c \
						bonus/srcs/Movement/key_manager.c \
						bonus/srcs/Movement/moves.c \
						bonus/srcs/Movement/enemy_moves.c \
						bonus/srcs/Parsing/is_map_valid.c \
						bonus/srcs/Parsing/parse_args.c \
						bonus/srcs/Parsing/parse_map.c \
						bonus/srcs/Render/animation.c \
						bonus/srcs/Render/drawing.c \
						bonus/srcs/Render/pixel_put.c \
						bonus/srcs/Render/textures_loading.c \
						bonus/srcs/Render/display_num.c \
						bonus/srcs/Render/locate_enemy.c

# ------------------------------------------------------------------------------


# ------------------------------------------------------------------------------

INCLUDES		=	./libft/libft.h \
						./includes/so_long.h \
						./includes/mlx.h \

INCLUDES_BONUS	=	./libft/libft.h \
						./bonus/includes/so_long.h \
						./bonus/includes/mlx.h \

HEAD			=	./includes/

HEAD_BONUS		=	./bonus/includes/

LIBFT			=	./libft/libft.a

#		Compilation Linux
#MLX				=	./mlx_lib/libmlx_Linux.a

MLX				=	./mlx_lib/libmlx.a

MLX_DIR			=	./mlx_lib/

LIB_DIR			=	./libft/

NAME			=	so_long

NAME_B			=	so_long_b

CC				=	clang

OBJS			=	${SRCS:.c=.o}

OBJS_B			=	${SRCS_BONUS:.c=.o}

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address



#		Compilation Linux
#LFLAGS			=	-lm -lX11 -lXext -lbsd

LFLAGS			=	-framework OpenGL -framework AppKit

#${OBJS_DIR}/%.o: *.c
#				@mkdir -p ${OBJS_DIR}
#				@${CC} ${CFLAGS} -I${HEAD} -c $< -o $@
#				@echo "${GREEN}[LOADED] ${WHITE}$@"

#${OBJS_DIRB}/%.o: *.c
#				@${CC} ${CFLAGS} -I${HEAD_BONUS} -c $< -o $@
#				@echo "${GREEN}[LOADED] ${WHITE}$@"

.c.o:
					@${CC} ${CFLAGS} -I${HEAD} -c $< -o $@
					@echo "${GREEN}[LOADED] ${WHITE}$@"

all:			${NAME}

${NAME}:		${OBJS}
					@make -C ${MLX_DIR} 2>/dev/null
					@make -C ${LIB_DIR}
					@make -C ${LIB_DIR} bonus
					@${CC} ${CFLAGS} ${LFLAGS} -I${HEAD} -o ${NAME} ${OBJS} ${LIBFT} ${MLX}
					@echo "\n${GREEN}						    [SO_LONG LOADED 100%]"
					@sleep 1
					@echo "${BLUE}\n[libmlx.a] has been created"
					@echo "[libft.a] has been created"
					@echo "[so_long] has been created"
					@sleep 1
					@echo "${YELLOW}\n\ninput : ./so_long ./Maps/name_of_the_map.ber"
					@sleep 1
					@echo "\n\n	${WHITE}					Aide Spider-Man a manger tous les burgers ! Bonne chance ! :)"
					@sleep 1
					@echo "\n 		commands : up -> W        left -> A        down -> S        right -> D      Leave -> Esc\n"

bonus:			${OBJS_B}
					@make -C ${MLX_DIR} 2>/dev/null
					@make -C ${LIB_DIR}
					@make -C ${LIB_DIR} bonus
					@${CC} ${CFLAGS} ${LFLAGS} -I${HEAD_BONUS} -o ${NAME_B} ${OBJS_B} ${LIBFT} ${MLX}
					@echo "\n${GREEN}						    [SO_LONG BONUS LOADED 100%]"
					@echo "${BLUE}\n[libmlx.a] has been created"
					@echo "[libft.a] has been created"
					@echo "[so_long bonus] has been created\n"
					@sleep 1
					@echo "${YELLOW}\n\ninput : ./so_long_b ./Maps/name_of_the_map.ber"
					@sleep 1
					@echo "\n\n	${WHITE}					Aide Spider-Man a manger tous les burgers pour ouvrir la porte ! Attention au chien ! Bonne chance ! :)"
					@sleep 1
					@echo "\n 		commands : up -> W        left -> A        down -> S        right -> D        Leave -> Esc        Shooting laser gun -> work in progress...\n"

clean:				
					@make -C ${LIB_DIR} clean
					@make -C ${MLX_DIR} clean
					@${RM} ${OBJS}
					@${RM} ${OBJS_B}
					@rm -rf ${OBJS_DIR}
					@rm -rf ${OBJS_DIRB}
					@echo "					${RED}.o files ${WHITE}have been deleted."
					@sleep 1

fclean:			clean
					@make -C ${LIB_DIR} fclean
					@${RM} ${NAME}
					@${RM} ${NAME_B}
					@echo "			  	  ${RED}libft.a ${WHITE}and ${RED}so_long ${WHITE}have been deleted."
					@sleep 1

re:				fclean all

.PHONY:			all	clean	fclean	re
