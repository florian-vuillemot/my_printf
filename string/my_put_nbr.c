/*
** my_put_nbr.c for put in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 15:44:13 2015 Florian Vuillemot
** Last update Sun Nov 15 18:17:38 2015 Florian Vuillemot
*/

#include		"my_string.h"

static unsigned int	get_size_nb(long int nb)
{
  unsigned int		res;

  if (nb < 0)
    res = 2;
  else if (nb > 0)
    res = 1;
  else
    return (2);
  while (nb != 0)
    {
      res = res + 1;
      nb = nb / 10;
    }
  return (res);
}

char			*my_putnbr_string(long int nb)
{
  char			*res;
  unsigned int		curs;
  long int		nb_base;

  if ((res = malloc(sizeof(char) * (curs = get_size_nb(nb)))) == NULL)
    return (NULL);
  curs = curs - 1;
  res[curs] = '\0';
  if (nb == 0)
    res[0] = '0';
  nb_base = nb;
  while (nb_base)
    {
      curs = curs - 1;
      if (nb < 0)
	res[curs] = (nb_base % 10) * -1 + '0';
      else
	res[curs] = nb_base % 10 + '0';
      nb_base = nb_base / 10;
    }
  if (nb < 0)
    res[curs - 1] = '-';
  return (res);
}

static unsigned int	get_ll_size_nb(long long int nb)
{
  unsigned int		res;

  if (nb < 0)
    res = 2;
  else if (nb > 0)
    res = 1;
  else
    return (2);
  while (nb != 0)
    {
      res = res + 1;
      nb = nb / 10;
    }
  return (res);
}

char			*my_put_ll_nbr(long long int nb)
{
  char			*res;
  unsigned int		curs;
  long long int		nb_base;

  if ((res = malloc(sizeof(char) * (curs = get_ll_size_nb(nb)))) == NULL)
    return (NULL);
  curs = curs - 1;
  res[curs] = '\0';
  if (nb == 0)
    res[0] = '0';
  nb_base = nb;
  while (nb_base)
    {
      curs = curs - 1;
      if (nb < 0)
	res[curs] = (nb_base % 10) * -1 + '0';
      else
	res[curs] = nb_base % 10 + '0';
      nb_base = nb_base / 10;
    }
  if (nb < 0)
    res[curs - 1] = '-';
  return (res);
}
