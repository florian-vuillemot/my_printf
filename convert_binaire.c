/*
** convert_hexa.c for convert in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 17:40:06 2015 Florian Vuillemot
** Last update Tue Nov 10 20:13:12 2015 Florian Vuillemot
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
  while (curs < (sizeof(long int) * 8))
    {
      if (nb & (one << curs))
	size = curs;
      curs = curs + 1;
    }
  return (size + 2);
}

char			*convert_binaire(unsigned long int nb)
{
  char			*res;
  unsigned long int	curs;
  int			size;
  unsigned long int	one;

  size = get_size(nb);
  if ((res = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  res[size - 1] = '\0';
  size = size - 2;
  one = 1;
  curs = 0;
  while (size > -1)
    {
      if (nb & (one << curs))
	res[size] = '1';
      else
	res[size] = '0';
      size = size - 1;
      curs = curs + 1;
    }
  return (res);
}
