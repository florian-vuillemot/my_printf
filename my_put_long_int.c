/*
** print_integer_short_integer.c for N] in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 08:04:24 2015 Florian Vuillemot
** Last update Wed Nov  4 12:12:59 2015 Florian Vuillemot
*/

#include	"my_put_number.h"

static int	my_put_positiv_long_int(long int nb)
{
  int		value;

  value = 0;
  if (nb < 10)
    {
      my_putchar(nb + '0');
      return (1);
    }
  value = my_put_positiv_long_int(nb / 10);
  my_putchar(nb % 10 + '0');
  return (1 + value);
}

static int	my_put_negativ_long_int(long int nb)
{
  int		value;

  value = 0;
  if (nb > -10)
    {
      my_putchar(nb * -1 + '0');
      return (1);
    }
  value = my_put_negativ_long_int(nb / 10);
  my_putchar((nb % 10) * -1 + '0');
  return (1 + value);
}

int		my_put_long_int(long int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      return (my_put_negativ_long_int(nb) + 1);
    }
  return (my_put_positiv_long_int(nb));
}
