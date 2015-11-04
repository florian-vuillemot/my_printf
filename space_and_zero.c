/*
** my_printf.c for my_printf in /home/vuille_f/my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  2 15:41:04 2015 Florian Vuillemot
** Last update Wed Nov  4 18:22:34 2015 Florian Vuillemot
*/

#include "my_string.h"

void		analyse_space_and_zero_in_string(int *nb_z,
						 int *space,
						 char *str,
						 int *cursor)
{
  int		zero;

  zero = 0;
  if (!str || !space || !nb_z || !cursor)
    return ;
  while (str[*cursor] && (str[*cursor] == '+' || str[*cursor] == '-'))
    *cursor = *cursor + 1;
  while (str[*cursor] && (str[*cursor] == '0' || str[*cursor] == ' '))
    {
      if (str[*cursor] == ' ')
	*space = 1;
      if (str[*cursor] == '0')
	zero = 1;
      *cursor = *cursor + 1;
    }
  if (zero)
    {
      *nb_z = my_getnbr(&(str[*cursor]));
      if (*nb_z < 1)
	*nb_z = -1;
      while (str[*cursor] && str[*cursor] >='0' && str[*cursor] <= '9')
	*cursor = *cursor + 1;
    }
}

void		put_space_and_zero(int nb_zero, int space)
{
  if (space)
    my_putchar(' ');
  while (nb_zero > 0)
    {
      my_putchar('0');
      nb_zero = nb_zero - 1;
    }
}

int		space_or_zero_in_front_of_the_string(char *str)
{
 /*  while (*c && *c == '+') */
/*     c = c + 1; */
/*   if (*c == '-') */
/*     return (0); */
/* q */  return (1);
}
