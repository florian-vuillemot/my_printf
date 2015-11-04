##
## Makefile for makefile in /home/vuille_f/CPE_year_Pushswap
## 
## Made by Florian Vuillemot
## Login   <vuille_f@epitech.net>
## 
## Started on  Tue Nov  3 13:51:45 2015 Florian Vuillemot
## Last update Wed Nov  4 14:51:30 2015 Florian Vuillemot
##

CC		=	gcc

NAME		=	my_printf

CFLAGS		=	-Wall -Wextra -W #-Werror

LDFLAGS		=

SRCS		=	main.c					\
			my_printf.c				\
			error_my_printf.c			\
			my_putnbr_base.c			\
			print_char_string_all_string.c		\
			my_getnbr_base.c			\
			my_string.c				\
			print_integer_short_long.c		\
			my_put_long_int.c			\
			print_pointer_hexa_octal_binaire.c	\
			print_upper_short.c			\

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re