# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 17:29:38 by vpalacio          #+#    #+#              #
#    Updated: 2023/12/06 14:56:29 by vpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc -g
SRCS		=	 main.c \
				./checker/check_input.c \
				./checker/check_input1.c \
				./utils/utils.c \
				./utils/utils1.c \
				./parser/parse.c \
				./executor/execute.c ./executor/execute1.c \
				./gnl/get_next_line.c \
				./gnl/get_next_line_utils.c \
				
			
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C mlx_linux/
		cp mlx_linux/libmlx.a .
		$(CC) $(OBJS) libmlx.a $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

%o:	%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

run:		all
			./$(NAME) 

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
	$(RM) *.out
	$(RM) libmlx.a

re:			fclean all

.PHONY:		all clean fclean re