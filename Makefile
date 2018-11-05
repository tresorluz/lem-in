# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tluzing <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 17:53:28 by tluzing           #+#    #+#              #
#    Updated: 2018/09/18 18:00:53 by tluzing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= lem_in

CFLAGS = -Wall -Wextra -Werror

SRCS =  srcs/is_error.c srcs/initialize_struct.c srcs/lem_in.c srcs/create_list.c srcs/movement.c\
        srcs/store_info.c srcs/solution.c

OBJS =  is_error.o initialize_struct.o lem_in.o create_list.o movement.o store_info.o solution.o

HEADERS = -I libft/includes -I includes/

LIB = libft/libft.a

$(NAME) :
	@make fclean -C libft/
	@make -C libft/
	@make clean -C libft/
	@gcc $(CFLAGS) -c $(SRCS) $(HEADERS)
	@gcc $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)
	@make clean
	@echo "\x1B[32mlem_in compiled successfully_axis\x1B[1m"


all : $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re : fclean all
