/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Sat Nov 14 10:08:22 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

static void		set_width_prec_string(t_node_va_arg *node,
					      t_width_prec *wi_prec,
					      t_string *string)
{
  if (!string || !wi_prec || !wi_prec)
    return ;
  if (node->type == CHARACTER)
    wi_prec->precision = 1;
  if (my_strlen(node->arg) > wi_prec->precision)
    node->arg[wi_prec->precision] = '\0';
  if (wi_prec->width > wi_prec->precision)
    wi_prec->precision = wi_prec->width - wi_prec->precision;
}

t_string		*get_with_flag_string(t_string *string,
					      unsigned int *cursor,
					      t_list_va_arg *list)
{
  unsigned int	       	minus;
  t_node_va_arg		*node;
  t_width_prec		wi_prec;

  if (!list || !string || !list->cursor || !string->string || !cursor)
    return (NULL);
  if ((node = list->cursor) == NULL)
    return (NULL);
  get_arg(list);
  if ((string = clean_string_data_string(string, cursor, &minus, node)) == 0)
    return (NULL);
  wi_prec.width = get_field_width(string, *cursor);
  if (string->string[*cursor] == '.')
    wi_prec.precision = get_string_precision(string, *cursor);
  else
    wi_prec.precision = -1;
  set_width_prec_string(node, &wi_prec, string);
  if ((string = remove_elem_to_string(string, *cursor)) == NULL)
    return (NULL);
  if (minus == 1)
    return (get_width_prec_string_minus(string, &wi_prec, *cursor, node));
  return (get_width_prec_string(string, &wi_prec, *cursor, node));
}
