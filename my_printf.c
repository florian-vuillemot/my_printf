/*
** my_printf.c for my_printf in /home/vuille_f/my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  2 15:41:04 2015 Florian Vuillemot
** Last update Tue Nov  3 22:31:07 2015 Florian Vuillemot
*/

#include "my_printf.h"

static t_flag_and_fct	tab_flag_and_function[] = 
{
			{"c", &print_char},
			{"s", &print_string},
			{"S", &print_string_and_all_char},
			/* {"d", &print_integer}, */
			/* {"i", &print_integer}, */
			/* {"u", &print_unsigned}, */
			/* {"f", &print_float}, */
			/* {"l", &print_long}, */
			/* {"p", &print_pointer}, */
			/* {"hd", &print_short}, */
			/* {"x", &print_hexa}, */
			/* {"o", &print_octal}, */
			{0, 0}
};

int		cmp_flags(char *ope, char *string)
{
  if (!ope || !string)
    return (0);
  while (*ope && *string && *ope == *string)
    {
      ope = ope + 1;
      string = string + 1;
    }
  if (*ope)
    return (1);
  return (0);
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
	    nb_read = nb_read - 2 +
	      tab_flag_and_function[j].flag_fct(string, &i, &list_of_argument);
	  else
	    {
	      my_putchar('%');
	      nb_read = nb_read + 1;
	    }
  	}
      else
  	my_putchar(string[i]);
      i = i + 1;
      nb_read = nb_read + 1;
    }
  return (nb_read + 1);
}
