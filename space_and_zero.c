/*
** my_printf.c for my_printf in /home/vuille_f/my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  2 15:41:04 2015 Florian Vuillemot
** Last update Wed Nov  4 23:28:00 2015 Florian Vuillemot
*/

#include "my_string.h"

void		analyse_space_and_zero_in_string(int *nb_z,
						 int *space,
						 char *str,
						 int *cursor)
{
  if (!str || !space || !nb_z || !cursor)
    return ;
  while (str[*cursor] &&
	 (str[*cursor] == '+' || str[*cursor] == '-' ||
	  str[*cursor] == ' ' || str[*cursor] == '0'))
    {
      if (str[*cursor] == ' ')
	*space = 1;
      *cursor = *cursor + 1;
    }
  *nb_z = my_getnbr(&(str[*cursor]));
  while (str[*cursor] && str[*cursor] >='0' && str[*cursor] <= '9')
    *cursor = *cursor + 1;
}

int		put_space_and_zero(int nb_zero, int space, char char_to_print)
{
  int		nb_read;

  if (nb_zero < 0)
    return (0);
  nb_read = nb_zero;
  if (space)
    my_putchar(' ');
  while (nb_read > 0)
    {
      my_putchar(char_to_print);
      nb_read = nb_read - 1;
    }
  return (nb_zero);
}

char		get_char_to_print(char *str)
{
  while (*str && (*str == '+' || *str == ' '))
    str = str + 1;
  if (*str == '0')
    return ('0');
  return (' ');
}

int		print_in_front_of(char *str)
{
  while (*str && (*str == '+' || *str == ' ' || *str == '0'))
    str = str + 1;
  if (*str == '-')
    return (0);
  return (1);
}
