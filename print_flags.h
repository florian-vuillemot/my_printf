/*
** print_flag.h for prit in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov  3 20:08:19 2015 Florian Vuillemot
** Last update Wed Nov  4 09:39:12 2015 Florian Vuillemot
*/

#ifndef			PRINT_FLAGS_H_
# define		PRINT_FLAGS_H_

# include		<stdarg.h>
# include		"my_string.h"
# include		"my_put_number.h"

/* print_char_string_all_string.c */
int			print_char(char *, int *, va_list *);
int			print_string(char *, int *, va_list *);
int			print_string_and_all_char (char *, int *,
						   va_list *);

/* print_integer_short_unsigned.c */
int			print_integer(char *, int *, va_list *);
int			print_unsigned(char *, int *, va_list *);
int			print_long(char *, int *, va_list *);

/* print_pointer_hexa_octalc */
int			print_pointer(char *, int *, va_list *);

#endif /* PRINT_FLAGS_H_ */
