/*
** print_upper.c for upper_case in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 13:53:31 2015 Florian Vuillemot
** Last update Wed Nov  4 14:42:10 2015 Florian Vuillemot
*/

#include		"print_flags.h"

int			print_upper_hexa(char *str, int *cursor,
					 va_list *list)
{
  unsigned long int	nb;

  nb = (unsigned long int)va_arg(list, unsigned int);
  while (str[*cursor] != 'X')
    *cursor = *cursor + 1;
  return (my_put_long_unsigned_nbr_base(nb, "0123456789ABCDEF"));
}

int			print_short(char *str, int *cursor,
					 va_list *list)
{
  short int		nb;

  nb = (short int)va_arg(list, int);
  while (str[*cursor] != 'd')
    *cursor = *cursor + 1;
  return (my_put_long_int((long int)nb));
}
