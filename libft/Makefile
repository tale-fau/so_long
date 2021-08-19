# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 19:01:04 by tale-fau          #+#    #+#              #
#    Updated: 2021/08/18 17:03:53 by tale-fau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;91m
GREEN = \033[0;92m
BLUE = \033[0;34m
WHITE = \x1b[0m

NAME		=	libft.a

SRCS		=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_tablen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strjoinfree.c

SRCS_BONUS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

HEAD		= libft.h

OBJS		= ${SRCS:%.c=${OBJS_DIR}/%.o}

OBJS_BONUS	= ${SRCS_BONUS:%.c=${OBJS_DIR}/%.o}

OBJS_DIR	= ./objs

NAME		= libft.a

CC		= clang

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

${OBJS_DIR}/%.o: %.c
		@mkdir -p ${OBJS_DIR}
		@${CC} ${CFLAGS} -I. -c $< -o $@
		@echo "${GREEN}[LOADED] ${WHITE}$@"

$(NAME):	${OBJS}
		@ar rc ${NAME} ${OBJS}
		@echo "${GREEN}							[LIBFT LOADED 100%]"
		@sleep 1

bonus:		${NAME} ${OBJS} ${OBJS_BONUS}
		@ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

all:		${NAME}

clean:
		@${RM} ${OBJS} ${OBJS_BONUS}
		@rm -rf ${OBJS_DIR}

fclean:		clean
		@${RM} ${NAME}

re:		fclean all

.PHONY:		all    clean    fclean re bonus
