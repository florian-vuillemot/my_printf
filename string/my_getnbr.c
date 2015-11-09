/*
** my_getnbr_base.c for  in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 16:42:57 2015 Florian Vuillemot
** Last update Sun Nov  8 17:45:52 2015 Florian Vuillemot
*/

#include	"my_string.h"

static long int	my_get_negativ_nbr(char *str, long int mult)
{
  if (!str || !mult || *str < '0' || *str > '9')
    return (0);
  return ((*str - '0')* mult - my_get_negativ_nbr(str + 1, mult - 10));
}

static long int	my_get_positif_nbr(char *str, long int mult)
{
  if (!str || !mult || *str < '0' || *str > '9')
    return (0);
  return ((*str - '0') * mult + my_get_positif_nbr(str + 1, mult - 10));
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

  nb = 0;
  nb_long = 0;
  if (nb < 0)
    nb_long = my_get_negativ_nbr(str, get_nb_zero(str));
  else
    nb_long = my_get_positif_nbr(str, get_nb_zero(str));

  nb = (int)nb_long;
  if ((long int)nb != nb_long)
    return (-1);
  return (nb);
}
