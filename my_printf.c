/*
** test.c for test in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 17:25:12 2015 Florian Vuillemot
** Last update Thu Nov 12 09:42:57 2015 Florian Vuillemot
*/

//#include		"my.h"

#include		<stdarg.h>
#include		"pars.h"
#include		"list_va_arg.h"
#include		"get_elem_to_print.h"

int			my_printf(char *str, ...)
{
  va_list		list;
  t_list_va_arg		*arg;
  t_flag		*flag;
  int			res;
  t_string		*string;

  if (!str)
    return (-1);
  va_start(list, str);
  if ((flag = init_flag_and_fct()) == 0 || (string = parse(str, flag)) == 0)
    return (-1);
  arg = init_list_va_arg(flag, string->string, &list);
  if (arg && (string = get_elem_to_print(string, flag, arg)) == NULL)
    return (-1);
  print_string(string);
  res = string->cursor;
  free_string(string);
  free_flag_and_fct(flag);
  free_list_va_arg(arg);
  va_end(list);
  return (res);
}
