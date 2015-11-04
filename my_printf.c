/*
** my_printf.c for my_printf in /home/vuille_f/my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  2 15:41:04 2015 Florian Vuillemot
** Last update Wed Nov  4 18:24:56 2015 Florian Vuillemot
*/

#include "my_printf.h"

static t_flag_and_fct	tab_flag_and_function[] = 
{
			{"c", &print_char},
			{"s", &print_string},
			{"S", &print_string_and_all_char},
			{"d", &print_integer},
			{"i", &print_integer},
			{"u", &print_unsigned},
			{"ld", &print_long},
			{"f", &print_float},
			/* {"F", &print_float}, */
			{"p", &print_pointer},
			{"x", &print_hexa},
			{"o", &print_octal},
			{"b", &print_binaire},
			{"X", &print_upper_hexa},
			{"hd", &print_short},
			{0, 0}
};

int		cmp_flags(char *ope, char *string)
{
  int		nb_zero;
  int		space;
  int		cursor;

  nb_zero = -1;
  space = 0;
  cursor = 0;
  if (!ope || !string)
    return (0);
  analyse_space_and_zero_in_string(&nb_zero, &space, string, &cursor);
  while (*ope && string[cursor] && *ope == string[cursor])
    {
      ope = ope + 1;
      cursor = cursor + 1;
    }
  if (*ope)
    return (1);
  return (0);
}

void		my_printf_treate_pourcent(char *str, int *i, int *nb_read)
{
  my_putchar('%');
  *i = *i + 1;
  if (str[*i] != '%')
    {
      my_putchar(str[*i]);
      *nb_read = *nb_read + 2;
    }
}

int		my_printf(char *string, ...)
{
  va_list	list_of_argument;
  int		i;
  int		j;
  int		nb_read;

  i = 0;
  nb_read = 0;
  va_start(list_of_argument, string);
  while (string[i])
    {
      if (string[i] == '%')
  	{
	  j = 0;
	  while (cmp_flags(tab_flag_and_function[j].flag, &string[i + 1]))
	    j = j + 1;
	  if (tab_flag_and_function[j].flag_fct)
	    nb_read = nb_read - 1 +
	      tab_flag_and_function[j].flag_fct(string, &i, &list_of_argument);
	  else
	    my_printf_treate_pourcent(string, &i, &nb_read);
  	}
      else
  	my_putchar(string[i]);
      i = i + 1;
      nb_read = nb_read + 1;
    }
  return (nb_read);
}
