/*
** float.c for floa in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 18:02:09 2015 Florian Vuillemot
** Last update Wed Nov  4 19:00:35 2015 Florian Vuillemot
*/

#include	"print_flags.h"

int		print_float(char *str, int *cursor, va_list *list)
{
  float		nb;
  int		integer;
  int		mult;
  float		res;

  mult = 1;
  nb = (float)va_arg(list, double);
  integer = (int)nb;
  my_put_long_int((long int)integer);
  if (nb == integer)
    {
      my_putstr(".00");
      return ;
    }
  res = nb * mult - integer;
  my_putchar('.');
  while (res > 0 && (res + '0') >= '0' && (res + '0') <= '9')
    {
      mult = mult * 10;
      integer = integer * 10;
      res = nb * mult - integer;
      if (res > 0 && (res + '0') >= '0' && (res + '0') <= '9')
	my_putchar((int)(nb * mult - integer) + '0');
    }
  return (1);
}
