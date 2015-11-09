/*
** my_getnbr_base.c for  in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 16:42:57 2015 Florian Vuillemot
** Last update Tue Nov 10 00:46:20 2015 Florian Vuillemot
*/

#include	"my_string.h"

static long int	my_get_positif_nbr(char *str, long int mult)
{
  if (!str || *str < '0' || *str > '9')
    return (0);
  if (mult > 0)
    return ((*str - '0') * mult + my_get_positif_nbr(str + 1, mult - 10));
  return ((*str - '0') + my_get_positif_nbr(str + 1, mult - 10));
}
  
static long int	get_nb_zero(char *str)
{
  long int	nb_zero;

  if (!str)
    return (0);
  nb_zero = 1;
  while (*str && *str >= '0' && *str <= '9')
    {
      nb_zero = nb_zero * 10;
      str = str + 1;
    }
  return (nb_zero / 10);
}

int		my_getnbr(char *str)
{
  int		nb;
  long int	nb_long;
  int		sign;

  nb = 0;
  nb_long = 0;
  sign = 1;
  while (*str == '-' || *str == '+' || *str == ' ')
    {
      if (*str == '-')
	sign = -1;
      str = str + 1;
    }
  while (*str == '0')
    str = str + 1;
  if (!*str)
    return (0);
  nb_long = my_get_positif_nbr(str, get_nb_zero(str)) * sign;
  nb = (int)nb_long;
  if ((long int)nb != nb_long)
    return (-1);
  return (nb);
}
