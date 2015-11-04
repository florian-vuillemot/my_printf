/*
** print_pointer_hexa_octal.c for HOP in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 09:30:33 2015 Florian Vuillemot
** Last update Wed Nov  4 11:17:31 2015 Florian Vuillemot
*/

#include	"print_flags.h"

int		print_pointer(char *str, int *cursor, va_list *list)
{
  while (str[*cursor] != 'p')
    *cursor = *cursor + 1;
  long int address = va_arg(list, long int *);
  return (my_put_long_unsigned_nbr_base(address, "0123456789abcdef"));
}
