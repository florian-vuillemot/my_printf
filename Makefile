##
## Makefile for makefile in /home/vuille_f/CPE_year_Pushswap
## 
## Made by Florian Vuillemot
## Login   <vuille_f@epitech.net>
## 
## Started on  Tue Nov  3 13:51:45 2015 Florian Vuillemot
## Last update Thu Nov 12 16:51:26 2015 Florian Vuillemot
##

CC		=	gcc $(LDFLAGS)

LDFLAGS		=	-I./flag/						\
			-I./flag_fct/						\
			-I./get_elem_to_print/					\
			-I./list_va_arg/					\
			-I./parsing/						\
			-I./string/						\


NAME		=	libmy.a

CFLAGS		=	-Wall -Wextra -W #-Werror

SRCS		= 	flag/cmp_string_and_flag.c				\
			flag_fct/convert_binaire.c				\
			flag_fct/convert_char_octal.c				\
			flag_fct/convert_hexa.c					\
			flag_fct/convert_octal.c				\
			flag_fct/flag_function.c				\
			flag_fct/flag_hexa_octal_binaire.c			\
			flag_fct/flag_integer_long_short.c			\
			flag_fct/flag_j_z.c					\
			flag_fct/flag_p.c					\
			flag_fct/flag_string.c					\
			flag_fct/flag_unsigned_long_short.c			\
			flag/flag_and_fct.c					\
			flag/flag_with_fct.c					\
			flag/use_flag.c						\
			get_elem_to_print/get_attribut.c			\
			get_elem_to_print/get_elem_to_print.c			\
			get_elem_to_print/get_field_width.c			\
			get_elem_to_print/get_flag_and_convert.c		\
			get_elem_to_print/get_flag_integer.c			\
			get_elem_to_print/get_flag_string.c			\
			get_elem_to_print/get_width_precision.c			\
			get_elem_to_print/get_width_precision_convert.c		\
			get_elem_to_print/get_width_precision_string.c		\
			get_elem_to_print/get_width_precision_pnt.c		\
			get_elem_to_print/get_flag_pnt.c			\
			list_va_arg/get_elem_list_va_arg.c			\
			list_va_arg/list_va_arg.c				\
			list_va_arg/node_va_arg.c				\
			parsing/operator_parse.c				\
			parsing/pars.c						\
			string/init_struct_string.c				\
			string/mouv_elem_string.c				\
			string/my_comp_string.c					\
			string/my_getnbr.c					\
			string/my_put_llu_nbr.c					\
			string/my_put_nbr.c					\
			string/my_string.c					\
			string/read_string.c					\
			string/write_on_string.c				\
			my_printf.c						\


OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

all: 			$(NAME)

$(NAME):		$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
