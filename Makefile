# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 08:22:33 by nsierra-          #+#    #+#              #
#    Updated: 2014/05/19 08:55:18 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_select

INC_FILES	=	ft_select.h

SRC_FILES	=	main.c \
				delete_element.c \
				print_list.c \
				get_env.c \
				exit_ftselect.c \
				init_termcaps.c \
				signal_handler.c \
				restore_termcaps.c \
				ft_putrchar.c

SRC			=	$(addprefix src/, $(SRC_FILES))
INC			=	$(addprefix inc/, $(INC_FILES))
OBJ			=	$(SRC:.c=.o)

CC			=	gcc
MAKE		=	make

CFLAGS		=	-g3 -Wall -Wextra -Werror
IFLAGS		=	-I./inc/ -I./libft/ -I./ftlst/
LDFLAGS		=	-L./libft/ -lft -L./ftlst/ -lftlst -ltermcap


$(NAME):		$(INC) $(OBJ)
				$(MAKE) -C ftlst/
				$(MAKE) -C libft/
				$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $@

all:			$(NAME)

%.o:			%.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
				$(MAKE) -C libft/ clean
				$(MAKE) -C ftlst/ clean
				rm -rf $(OBJ)

fclean:			clean
				$(MAKE) -C libft/ fclean
				$(MAKE) -C ftlst/ fclean
				rm -f $(NAME)

re:				fclean all

.PHONY:
