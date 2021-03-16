# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 14:57:04 by abelarif          #+#    #+#              #
#    Updated: 2021/02/23 17:03:17 by abelarif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D

LBFT_SRC=	./libft_utils/ft_atoi.c\
			./libft_utils/ft_isalpha.c\
			./libft_utils/ft_isdigit.c\
			./libft_utils/ft_putchar_fd.c\
			./libft_utils/ft_putstr_fd.c\
			./libft_utils/ft_split.c\
			./libft_utils/ft_strdup.c\
			./libft_utils/ft_strlen.c\
			./libft_utils/ft_strncmp.c\

GNL_SRC=	./gnl/get_next_line.c\
			./gnl/get_next_line_utils.c\

SRCS=		calc_help.c\
			check_map.c\
			data.c\
			data_utils.c\
			dda.c\
			dda_utils.c\
			free_list.c\
			ft_iswall.c\
			ft_save.c\
			get_data.c\
			key.c\
			link.c\
			main.c\
			map.c\
			map_2d.c\
			sprite.c\
			$(LBFT_SRC)\
			$(GNL_SRC)\

OBJS=		$(SRCS:.c=.o)

$(NAME): $(OBJS)			
	gcc -Wall -Werror -Wextra -o $(NAME) -framework OpenGL -framework AppKit -lmlx $(OBJS)

all : $(NAME)

clean:
			rm -rf $(OBJS)

fclean:
			rm -rf $(NAME) $(OBJS)

re: fclean all