/*
** my_put_nbr.c for put in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 15:44:13 2015 Florian Vuillemot
** Last update Thu Nov 12 06:43:22 2015 Florian Vuillemot
*/

#include		"my_string.h"

static unsigned int		get_size_nb(unsigned long long int nb)
{
  unsigned int			res;

  if (nb > 0)
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

char				*my_put_llu_nbr(unsigned long long int nb)
{
  char				*res;
  unsigned int			curs;

  if ((res = malloc(sizeof(char) * (curs = get_size_nb(nb)))) == NULL)
    return (NULL);
  curs = curs - 1;
  res[curs] = '\0';
  if (nb == 0)
    res[0] = '0';
  while (nb)
    {
      curs = curs - 1;
      res[curs] = nb % 10 + '0';
      nb = nb / 10;
    }
  return (res);
}
