/*
** get_field_width.c for  in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 15:02:50 2015 Florian Vuillemot
** Last update Mon Nov  9 16:11:26 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

unsigned int		get_field_width(t_string *string, unsigned int curs)
{
  int			nb;
  int			place_curs;

  if (!string || !string->string)
    return (0);
  place_curs = curs;
  nb = my_getnbr(string->string);
  while (string->string[curs] <= '9' && string->string[curs] >= '0')
    remove_elem_to_string(string, curs);
  if (nb < 0 && curs != place_curs)
    return (1 << (sizeof(int) * 8 - 1));
  if (nb < 0)
    return (0);
  return ((unsigned int)nb);
}

unsigned int		get_precision(t_string *string, unsigned int cur,
				      t_node_va_arg *node)
{
  unsigned int		precision;
  unsigned int		len;

  if (!string || !string->string)
    return (0);
  if (string->string[cur] != '.')
    return (0);
  remove_elem_to_string(string, cur);
  precision = get_field_width(string, cur);
  len = my_strlen(node->arg);
  if (len > precision)
    node->arg[len] = '\0';
  while (len < precision)
    {
      add_elem_to_string(string, cur, '0');
      precision = precision - 1;
    }
  return (precision);
}
