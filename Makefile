# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 11:20:11 by nkhamich          #+#    #+#              #
#    Updated: 2024/10/16 12:51:32 by nkhamich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
NAME_BONUS	= libft_bonus.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRC			= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c 

SRC_BONUS   = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
              ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
              ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(NAME_BONUS): $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

.PHONY: fclean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all