# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 19:54:32 by nsierra-          #+#    #+#              #
#    Updated: 2015/01/04 16:41:19 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftlst.a

SRC =		elem_destroy.c \
			elem_insert_between.c \
			elem_swap.c \
			lst_bubble_sort.c \
			lst_clear.c \
			lst_data_at.c \
			lst_data_back.c \
			lst_data_front.c \
			lst_del.c \
			lst_destroy.c \
			lst_elem_at.c \
			lst_elem_back.c \
			lst_elem_front.c \
			lst_get_size.c \
			lst_insert.c \
			lst_is_empty.c \
			lst_pop_back.c \
			lst_pop_front.c \
			lst_print.c \
			lst_push_back.c \
			lst_push_front.c \
			lst_remove.c \
			lst_swap.c \
			new_lst.c \
			new_lstelem.c


OBJ = 		$(SRC:.c=.o)

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I . -I../libft -c $(SRC)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTNAME)

re: fclean all

ret: fclean test
	./$(TESTNAME)
