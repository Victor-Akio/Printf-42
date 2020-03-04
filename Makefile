# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vminomiy <vminomiy@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 14:11:56 by vminomiy          #+#    #+#              #
#    Updated: 2020/03/04 06:18:20 by vminomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 		functions/ft_printf.c \
			functions/ft_handler.c functions/ft_print_c.c \
			functions/ft_print_width.c functions/ft_flags.c \
			functions/ft_print_s.c functions/ft_print_di.c \
			functions/ft_print_p.c functions/ft_print_u.c \
			functions/ft_print_x.c functions/ft_print_percent.c \
			libft\ft_isdigit.c libft\ft_isspace.c libft\ft_itoa_base.c \
			libft\ft_itoa_u.c libft\ft_itoa.c libft\ft_putchar.c \
			libft\ft_putlstr.c libft\ft_str_lowcase.c libft\ft_strdup.c \
			libft\ft_strlen.c libft\ft_strnew.c libft\ft_tolower.c

OBJECTS = 	ft_printf.o ft_handler.o ft_print_c.o ft_print_width.o \
			ft_flags.o ft_print_s.o ft_print_di.o ft_print_p.o \
			ft_print_u.o ft_print_x.o ft_print_percent.o \
			ft_isdigit.o ft_isspace.o ft_itoa_base.o \
			ft_itoa_u.o ft_itoa.o ft_putchar.o ft_putlstr.o \
			ft_str_lowcase.o ft_strdup.o ft_strlen.o ft_strnew.o ft_tolower.o

INCLUDES = includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS) 

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all