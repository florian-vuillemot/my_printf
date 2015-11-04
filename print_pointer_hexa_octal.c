/*
** print_pointer_hexa_octal.c for HOP in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 09:30:33 2015 Florian Vuillemot
** Last update Wed Nov  4 12:14:39 2015 Florian Vuillemot
*/

#include	"print_flags.h"

int			print_pointer(char *str, int *cursor,
				      va_list *list)
{
  unsigned long int	address;

  address = va_arg(list, unsigned long int);
  while (str[*cursor] != 'p')
    *cursor = *cursor + 1;
  my_putstr("0x");
  return (2 + my_put_long_unsigned_nbr_base(address, "0123456789abcdef"));
}

int			print_hexa(char *str, int *cursor,
				   va_list *list)
{
  unsigned long int	nb;

  nb = (unsigned long int)va_arg(list, unsigned int);
  while (str[*cursor] != 'x')
    *cursor = *cursor + 1;
  return (my_put_long_unsigned_nbr_base(nb, "0123456789abcdef"));
}


int			print_octal(char *str, int *cursor,
				    va_list *list)
{
  unsigned long int	nb;

  nb = (unsigned long int)va_arg(list, unsigned int);
  while (str[*cursor] != 'o')
    *cursor = *cursor + 1;
  return (my_put_long_unsigned_nbr_base(nb, "01234567"));
}
