/*
** print_char_string_all_string.c for sr in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov  3 20:05:15 2015 Florian Vuillemot
** Last update Wed Nov  4 23:23:31 2015 Florian Vuillemot
*/

#include "print_flags.h"


static int	get_nb_space_and_cursor(char *str, int *cursor,
					int *nb_space)
{
  int		pnt;
  int		space;

  *cursor = *cursor + 1;
  *nb_space = 0;
  space = print_in_front_of(str + *cursor);
  analyse_space_and_zero_in_string(nb_space, &pnt, str, cursor);
  return (space);
}

int		print_char(char *str, int *cursor, va_list *list)
{
  int		nb_space;
  int		space;
  int		cur;

  if ((space = get_nb_space_and_cursor(str, cursor, &nb_space)))
      nb_space = put_space_and_zero(nb_space - 1, 0, ' ');
  while (str[*cursor] && str[*cursor] != 'c')
    *cursor = *cursor + 1;
  my_putchar((char)va_arg(list, int));
  if (space == 0)
    nb_space = put_space_and_zero(nb_space - 1, 0, ' ');
  return (nb_space + 1);
}

int		print_string(char *str, int *cursor, va_list *list)
{
  char		*str_list;
  int		i;
  int		nb_space;
  int		space;
  int		cur;

  space = get_nb_space_and_cursor(str, cursor, &nb_space);
  while (str[*cursor] != 's')
    *cursor = *cursor + 1;
  if ((str_list = va_arg(list, char *)) == 0)
    return (error_my_printf());
  if (space)
    nb_space = put_space_and_zero(nb_space - (i = (int)my_strlen(str_list)),
				  0, ' ');
  my_putstr(str_list);
  if (space == 0)
    nb_space = put_space_and_zero(nb_space - (i = (int)my_strlen(str_list)),
				  0, ' ');
  return (nb_space + i);
}

static void	print_string_and_all_char_display_octal(char *str_list, int *i)
{
  my_putchar('\\');
  if (*str_list < 8)
    my_putchar('0');
  if (*str_list < 64)
    my_putchar('0');
  my_putnbr_base((int)*str_list, "01234567");
  *i = *i + 3;
}

int		print_string_and_all_char(char *str, int *cursor,
					  va_list *list)
{
  char		*str_list;
  int		i;
  int		nb_space;
  int		space;

  if ((str_list = va_arg(list, char *)) == 0)
    return (error_my_printf());
  i = my_octal_len(str_list + *cursor);
  if ((space = get_nb_space_and_cursor(str, cursor, &nb_space)))
    nb_space = put_space_and_zero(nb_space - i, 0, ' ');
  while (str[*cursor] != 'S')
    *cursor = *cursor + 1;
  while (*str_list)
    {
      if (*str_list < 32 || *str_list >= 127)
	print_string_and_all_char_display_octal(str_list, &i);
      else
	my_putchar(*str_list);
      str_list = str_list + 1;
    }
  if (space == 0)
    nb_space = put_space_and_zero(nb_space - i, 0, ' ');
  return (nb_space + i);
}
