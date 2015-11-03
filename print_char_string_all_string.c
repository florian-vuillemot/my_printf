/*
** print_char_string_all_string.c for sr in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov  3 20:05:15 2015 Florian Vuillemot
** Last update Tue Nov  3 22:36:50 2015 Florian Vuillemot
*/

#include "print_flags.h"

int		print_char(char *str, int *cursor, va_list *list)
{
  while (str[*cursor] != 'c')
    *cursor = *cursor + 1;
  my_putchar((char)va_arg(list, int));
  return (1);
}

int		print_string(char *str, int *cursor, va_list *list)
{
  char		*string_list;
  int		i;

  while (str[*cursor] != 's')
    *cursor = *cursor + 1;

  string_list = va_arg(list, char *);
  i = 0;
  while (*string_list)
    {
      my_putchar(*string_list);
      string_list = string_list + 1;
      i = i + 1;
    }
  return (i);
}

static void	print_string_and_all_char_display_octal(char *string_list)
{
  my_putchar('\\');
  if (*string_list < 8)
    my_putchar('0');
  if (*string_list < 64)
    my_putchar('0');
  my_putnbr_base((int)*string_list, "01234567");
}

int		print_string_and_all_char(char *str, int *cursor,
					  va_list *list)
{
  char		*string_list;
  int		i;

  while (str[*cursor] != 'S')
    *cursor = *cursor + 1;
  string_list = va_arg(list, char *);
  i = 0;
  while (*string_list)
    {
      if (*string_list < 32 || *string_list >= 127)
	print_string_and_all_char_display_octal(string_list);
      else
	my_putchar(*string_list);
      string_list = string_list + 1;
      i = i + 1;
    }
  return (i);
}
