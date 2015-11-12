/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Thu Nov 12 06:59:18 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

t_string		*get_with_flag_string(t_string *string,
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
  string = clean_string_data_string(string, cursor, &minus, node);
  wi_prec.width = get_field_width(string, *cursor);
  if (string->string[*cursor] == '.')
    wi_prec.precision = get_string_precision(string, *cursor);
  else
    wi_prec.precision = -1;
  if (node->type == CHARACTER)
    wi_prec.precision = 1;
  if (my_strlen(node->arg) > wi_prec.precision)
    node->arg[wi_prec.precision] = '\0';
  if (wi_prec.width > wi_prec.precision)
    wi_prec.precision = wi_prec.width - wi_prec.precision;
  string = remove_elem_to_string(string, *cursor);
  if (minus == 1)
    return (get_width_prec_string_minus(string, &wi_prec, *cursor, node));
  return (get_width_prec_string(string, &wi_prec, *cursor, node));
}
