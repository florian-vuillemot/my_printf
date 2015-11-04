/*
** print_integer_short_integer.c for N] in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 08:04:24 2015 Florian Vuillemot
** Last update Wed Nov  4 09:20:41 2015 Florian Vuillemot
*/

#include	"print_flags.h"

int		print_integer(char *str, int *cursor, va_list *list)
{
  int		nb_to_print;

  while (str[*cursor] != 'd' && str[*cursor] != 'i')
    *cursor = *cursor + 1;
  nb_to_print = va_arg(list, int);
  return (my_put_long_int((long int)nb_to_print));
}

int		print_unsigned(char *str, int *cursor, va_list *list)
{
  while (str[*cursor] != 'u')
    *cursor = *cursor + 1;
  return (my_put_long_int((long int)va_arg(list, unsigned int)));
}

int		print_long(char *str, int *cursor, va_list *list)
{
  while (str[*cursor] != 'd')
    *cursor = *cursor + 1;
  return (my_put_long_int(va_arg(list, long int)));
}
