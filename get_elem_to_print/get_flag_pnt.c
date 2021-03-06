/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Fri Nov 13 08:52:53 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

static unsigned int	put_complete_width(t_string *string,
					   unsigned int *cursor,
					   t_width_prec *wi_prec,
					   t_node_va_arg *node)
{
  char			complete_width;

  complete_width = node->complete_width;
  node->complete_width = ' ';
  string = add_complete_width(string, cursor, wi_prec, node);
  node->complete_width = complete_width;
  *cursor = *cursor + 1;
  return (2);
}

t_string		*get_flag_pnt(t_string *string,
				      unsigned int *cursor,
				      t_list_va_arg *list)
{
  unsigned int	       	minus;
  t_node_va_arg		*node;
  t_width_prec		wi_prec;
  unsigned int	       	minus2;

  if (!list || !string || !list->cursor || !string->string || !cursor)
    return (NULL);
  node = list->cursor;
  get_arg(list);
  string = clean_string_and_get_data(string, cursor, &minus, node);
  wi_prec.width = get_field_width(string, *cursor);
  if ((minus2 = minus) > 1)
    minus = minus - put_complete_width(string, cursor, &wi_prec, node);
  wi_prec.precision = get_precision(string, *cursor, node);
  string = remove_elem_to_string(string, *cursor);
  if (minus == 1)
    return (get_width_prec_pnt_convert_minus(string, &wi_prec, *cursor, node));
  return (get_width_prec_pnt_convert(string, &wi_prec, *cursor, node));
}
