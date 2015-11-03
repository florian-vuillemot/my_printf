/*
** my_putnbr_base.c for day06 in /home/vuille_f/rendu/Piscine_C_J06
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Oct  5 16:51:46 2015 Florian Vuillemot
** Last update Tue Nov  3 22:07:51 2015 Florian Vuillemot
*/

#include "my_string.h"

static void	rec_putnbre(long int nbr, long int nb_base, char *base)
{
  if (nbr < nb_base)
    {
      my_putchar(base[nbr]);
      return ;
    }
  rec_putnbre(nbr / nb_base, nb_base, base);
  my_putchar(base[nbr % nb_base]);
}

int		my_putnbr_base(int nbr, char *base)
{
  long int	nb;
  long int	nb_base;

  if (!base || *base == '\0')
    return (nbr);
  if (nbr < 0)
    {
      nb = nbr;
      nb = nb * -1;
      my_putchar('-');
    }
  else
    nb = nbr;
  nb_base = 0;
  while (base[nb_base])
    nb_base = nb_base + 1;
  rec_putnbre(nb, nb_base, base);
  return (nbr);
}
