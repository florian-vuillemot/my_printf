/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Wed Nov 11 23:43:53 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

t_string		*get_flag_integer_and_convert(t_string *string,
						      unsigned int *cursor,
						      int type_flag,
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
  wi_prec.width = get_field_width(string, *cursor, node);
  wi_prec.precision = get_precision(string, *cursor, node);
 if (minus == 3)
    {
      minus = minus - 2;
      if (wi_prec.precision > 0 && node->type == PRINT_OCTAL)
	wi_prec.precision = wi_prec.precision - 1;
    }
  string = remove_elem_to_string(string, *cursor);
  if (minus == 1)
    return (get_width_prec_convert_minus(string, &wi_prec, *cursor, node));
  return (get_width_prec_str_convert(string, &wi_prec, *cursor, node));
}