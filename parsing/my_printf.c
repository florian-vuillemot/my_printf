/*
** test.c for test in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 17:25:12 2015 Florian Vuillemot
** Last update Thu Nov 12 07:15:26 2015 Florian Vuillemot
*/

#include		"pars.h"
#include		"list_va_arg.h"
#include		"get_elem_to_print.h"

int			my_printf(const char *string, ...)
{
  va_list		*list;
  t_list_va_arg		*arg;

  va_start(list, string);
  arg = init_list_va_arg(flag, string->string, &list);
  if ((string = get_elem_to_print(string, flag, arg)) == NULL)
    my_putstr("Error\n");
  print_string(string);
  free_string(string);
  free_flag_and_fct(flag);
  va_end(list);
  return (0);
}
