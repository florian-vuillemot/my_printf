/*
** convert_hexa.c for convert in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 17:40:06 2015 Florian Vuillemot
** Last update Thu Nov 12 06:37:44 2015 Florian Vuillemot
*/

#include		"my_string.h"

static int		get_size(unsigned long int nb)
{
  int			curs;
  int			size;
  unsigned long int	one;

  curs = 0;
  size = 0;
  one = 1;
  while (curs < (int)(sizeof(long int) * 8))
    {
      if (nb & (one << curs))
	size = curs;
      curs = curs + 1;
    }
  size = size / 3;
  if (size == 0)
    return (2);
  return (size + 2);
}

static unsigned int	get_nb_octal(unsigned long int nb,
				     unsigned long int cursor)
{
  unsigned long int	max;
  unsigned int		res;
  unsigned long int	pow;
  unsigned long int	one;

  max = cursor + 3;
  res = 0;
  pow = 1;
  one = 1;
  while (cursor < max)
    {
      if (nb & (one << cursor))
	res = pow + res;
      pow = pow * 2;
      cursor = cursor + 1;
    }
  return (res);
}

char			*convert_octal(unsigned long int nb)
{
  char			*res;
  unsigned long int	curs;
  int			size;

  size = get_size(nb);
  if ((res = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  res[size - 1] = '\0';
  size = size - 2;
  curs = 0;
  while (size > -1)
    {
      res[size] = "01234567"[get_nb_octal(nb, curs)];
      size = size - 1;
      curs = curs + 3;
    }
  return (res);
}
