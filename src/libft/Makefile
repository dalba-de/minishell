# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 16:00:37 by dalba-de          #+#    #+#              #
#    Updated: 2019/11/17 22:43:17 by dalba-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

CC= gcc

CFLAGS= -Wall -Werror -Wextra -I. -c

SRC=	ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlen.c ft_toupper.c ft_bzero.c ft_putstr_fd.c ft_strmapi.c ft_calloc.c \
		ft_memccpy.c ft_split.c ft_strncmp.c ft_isalnum.c ft_memchr.c ft_strchr.c ft_strnstr.c ft_isalpha.c	ft_memcmp.c	\
		ft_strdup.c	ft_strrchr.c ft_isascii.c ft_memcpy.c ft_strjoin.c ft_strtrim.c ft_isdigit.c ft_memmove.c ft_strlcat.c \
		ft_substr.c ft_isprint.c ft_memset.c ft_strlcpy.c ft_tolower.c ft_putchar_fd.c ft_putendl_fd.c

BONUS=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ=	${SRC:.c=.o}

OBJB=	${BONUS:.c=.o}

all:	${NAME}

${NAME}:	${OBJ} libft.h
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

bonus:		${OBJ} ${OBJB} libft.h
	ar rc ${NAME} ${OBJ} ${OBJB}
	ranlib ${NAME}


clean:
	rm -f ${OBJ} ${OBJB}

fclean:		clean
			rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
