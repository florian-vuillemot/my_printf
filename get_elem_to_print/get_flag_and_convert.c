/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Fri Nov 13 21:45:40 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

t_string		*get_flag_integer_and_convert(t_string *string,
						      unsigned int *cursor,
						      t_list_va_arg *list)
{
  unsigned int	       	minus;
  t_node_va_arg		*node;
  t_width_prec		wi_prec;

  if (!list || !string || !list->cursor || !string->string || !cursor)
    return (NULL);
  node = list->cursor;
  get_arg(list);
  string = clean_string_data_convert(string, cursor, &minus, node);
  wi_prec.width = get_field_width(string, *cursor);
  wi_prec.precision = get_precision(string, *cursor, node);
  if (minus == 3)
    minus = minus - 2;
  string = remove_elem_to_string(string, *cursor);
  if (minus == 1)
    return (get_width_prec_convert_minus(string, &wi_prec, *cursor, node));
  return (get_width_prec_str_convert(string, &wi_prec, *cursor, node));
}
