/*
** my_putnbr_base.c for day06 in /home/vuille_f/rendu/Piscine_C_J06
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Oct  5 16:51:46 2015 Florian Vuillemot
** Last update Wed Nov  4 12:15:06 2015 Florian Vuillemot
*/

#include	"my_put_number.h"

static int	rec_putnbre(long int nbr, long int nb_base, char *base)
{
  int		res;

  if (nbr < nb_base)
    {
      my_putchar(base[nbr]);
      return (1);
    }
  res = rec_putnbre(nbr / nb_base, nb_base, base);
  my_putchar(base[nbr % nb_base]);
  return (res + 1);
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
      nbr = 1;
    }
  else
    {
      nb = nbr;
      nbr = 0;
    }
  nb_base = 0;
  while (base[nb_base])
    nb_base = nb_base + 1;
  return (rec_putnbre(nb, nb_base, base) + nbr);
}


static int	unsigned_rec_putnbre(unsigned long int nbr,
				     unsigned long int nb_base,
				     char *base)
{
  int		res;

  if (nbr < nb_base)
    {
      my_putchar(base[nbr]);
      return (1);
    }
  res = rec_putnbre(nbr / nb_base, nb_base, base);
  my_putchar(base[nbr % nb_base]);
  return (res + 1);
}

int		my_put_long_unsigned_nbr_base(unsigned long int nbr,
					      char *base)
{
  long int	nb_base;

  if (!base || *base == '\0')
    return (nbr);
  nb_base = 0;
  while (base[nb_base])
    nb_base = nb_base + 1;
  return (unsigned_rec_putnbre(nbr, (unsigned long int)nb_base, base));
}
