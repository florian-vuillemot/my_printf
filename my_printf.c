/*
** test.c for test in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 17:25:12 2015 Florian Vuillemot
** Last update Mon Nov 16 22:54:26 2015 Florian Vuillemot
*/

#include		<stdarg.h>
#include		"pars.h"
#include		"list_va_arg.h"
#include		"get_elem_to_print.h"

static int		free_and_return(t_string *string, t_flag *flag,
					t_list_va_arg *arg, char *c_str)
{
  int			res;

  if (string)
    {
      res = string->cursor;
      free_string(string);
    }
  else
    res = 0;
  if (flag)
    free_flag_and_fct(flag);
  if (arg)
    free_list_va_arg(arg);
  if (c_str)
    free(c_str);
  return (res);
}

int			my_printf(const char *str, ...)
{
  va_list		list;
  va_list		copy_l;
  t_list_va_arg		*arg;
  t_flag		*flag;
  t_string		*string;
  char			*c_str;

  if (!str || !(c_str = m_strdup(str)))
    return (-1);
  va_start(list, str);
  va_copy(copy_l, list);
  if ((flag = init_flag_and_fct()) == 0 || (string = parse(c_str, flag)) == 0)
    return (-1);
  arg = init_list_va_arg(flag, string->string, &list);
  if (arg && ((string = replace_dollar(string, arg, flag, &copy_l)) == NULL ||
	      (string = replace_star(string, arg, flag, &copy_l)) == NULL))
    return (-1);
  if (arg && (string = get_elem_to_print(string, flag, arg)) == NULL)
    return (-1);
  if ((string = clean_past_and_bad_flag(string, flag)) == NULL)
    return (-1);
  print_string(string);
  va_end(list);
  return (free_and_return(string, flag, arg, c_str));
}
