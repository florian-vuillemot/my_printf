/*
** get_field_width.c for  in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 15:02:50 2015 Florian Vuillemot
** Last update Sun Nov 15 19:06:36 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

unsigned int		get_field_width(t_string *string, unsigned int curs)
{
  int			nb;

  if (!string || !string->string)
    return (0);
  nb = my_getnbr(string->string + curs);
  while (string->string[curs] <= '9' && string->string[curs] >= '0')
    string = remove_elem_to_string(string, curs);
  if (nb <= 0)
    return (0);
  return ((unsigned int)nb);
}

unsigned int		get_precision(t_string *string, unsigned int cur,
				      t_node_va_arg *node)
{
  unsigned int		len;
  unsigned int		precision;
  int			get_nb;

  if (!string || !string->string || string->string[cur] != '.')
    return (0);
  string = remove_elem_to_string(string, cur);
  get_nb = my_getnbr(string->string + cur);
  len = my_strlen(node->arg);
  while (string->string[cur] <= '9' && string->string[cur] >= '0')
    string = remove_elem_to_string(string, cur);
  if (get_nb <= 0)
    return (0);
  precision = (unsigned int)get_nb;
  if (len < precision)
    precision = precision - len;
  else
    {
      precision = 0;
      node->complete_width = ' ';
    }
  return (precision);
}

unsigned int		get_string_precision(t_string *string,
					     unsigned int cur)
{
  int			get_nb;

  if (!string || !string->string || string->string[cur] != '.')
    return (0);
  string = remove_elem_to_string(string, cur);
  get_nb = my_getnbr(string->string + cur);
  while (string->string[cur] <= '9' && string->string[cur] >= '0')
    string = remove_elem_to_string(string, cur);
  if (get_nb <= 0)
    return (0);
  return ((unsigned int)get_nb);
}
