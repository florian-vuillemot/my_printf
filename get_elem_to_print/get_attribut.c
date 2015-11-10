/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Tue Nov 10 11:58:29 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

t_string		*get_flag_character(t_string *string,
					    unsigned int cursor,
					    t_list_va_arg *list,
					    t_flag *flag)
{
  int			nb_fg;

  if (!string || (nb_fg = contain_flag_fct(flag, string->string + cursor)) < 0
      || !list)
    return (NULL);
  //string = remove_elem_to_string(string, cursor);
  if (found_char_in_string(flag->flag_and_fct[nb_fg].flag[0], TYPE_INTEGER))
    {
      if (flag->flag_and_fct[nb_fg].flag[0] == 'i' ||
	  flag->flag_and_fct[nb_fg].flag[0] == 'u' ||
	  flag->flag_and_fct[nb_fg].flag[0] == 'd')
	return (get_flag_integer(string, &cursor, nb_fg, list));
      //  return (get_flag_integer_and_convert(string, cursor, nb_fg, list));
    }
  //  return (get_flag_string(string, cursor, nb_fg, list));
  return (NULL);
}

static	t_string	*clean_string_and_get_data(t_string *string,
						   unsigned int *cursor,
						   unsigned int *minus,
						   t_node_va_arg *node)
{
  if (!string || !node || !cursor || !minus)
    return (NULL);
  *minus = 0;
  if (string->string[*cursor] == '#')
    string = remove_elem_to_string(string, *cursor);
  if (string->string[*cursor] == ' ')
    {
      *minus = 2;
      string = remove_elem_to_string(string, *cursor);
    }
  if (string->string[*cursor] == '+')
    {
      if (node->type == INTEGER_POS)
	node->type = INTEGER_POS_WITH_PLUS;
      string = remove_elem_to_string(string, *cursor);
    }
  if (string->string[*cursor] == '-')
    {
      *minus = *minus + 1;
      string = remove_elem_to_string(string, *cursor);
      node->complete_width = ' ';
    }
  else if (string->string[*cursor] == '0')
    {
      node->complete_width = '0';
      string = remove_elem_to_string(string, *cursor);
    }
  return (string);
}

t_string		*get_flag_integer(t_string *string,
					  unsigned int *cursor,
					  int type_flag,
					  t_list_va_arg *list)
{
  int			minus;
  t_node_va_arg		*node;
  t_width_prec		width_precision;

  if (!list || !string || !list->cursor || !string->string || !cursor)
    return (NULL);
  node = list->cursor;
  get_arg(list);
  string = clean_string_and_get_data(string, cursor, &minus, node);
  width_precision.width = get_field_width(string, *cursor, node);
  if (minus == 3)
    {
      if (width_precision.width > 0)
	width_precision.width = width_precision.width - 1;
      else
	width_precision.width = 0;
      minus = minus - 2;
      if ((string = add_elem_to_string(string, *cursor, node->complete_width))
	  == NULL)
	return (NULL);
      *cursor = *cursor + 1;
    }
  width_precision.precision = get_precision(string, *cursor, node);
  string = remove_elem_to_string(string, *cursor);
  if (minus == 1)
    return (get_width_precision_string_minus(string, &width_precision,
  					     *cursor, node));
  return (get_width_precision_string(string, &width_precision, *cursor, node));
}

t_string		*get_width_precision_string(t_string *string,
						    t_width_prec *w_and_prec,
						    unsigned int cursor,
						    t_node_va_arg *node)
{
  unsigned int		len;

  if (!string || !string->string || !node || !node->arg || !w_and_prec)
    return (NULL);
  if (node->type == INTEGER_POS_WITH_PLUS)
    len = my_strlen(node->arg) + 1;
  else
    len = my_strlen(node->arg);
  while (w_and_prec->width > w_and_prec->precision + len)
    {
      string = add_elem_to_string(string, cursor, node->complete_width);
      w_and_prec->width = w_and_prec->width - 1;
      cursor = cursor + 1;
    }
  if (node->type == INTEGER_POS_WITH_PLUS)
    {
      len = len - 1;
      string = add_elem_to_string(string, cursor, '+');
      cursor = cursor + 1;
    }
  while (w_and_prec->precision)
    {
      string = add_elem_to_string(string, cursor, '0');
      w_and_prec->precision = w_and_prec->precision - 1;
      cursor = cursor + 1;
    }
  return (insert_string(string, node->arg, cursor));
}


t_string		*get_width_precision_string_minus(t_string *string,
							  t_width_prec *w_p,
							  unsigned int cursor,
							  t_node_va_arg *node)
{
  unsigned int		len;
  unsigned int		prec;

  if (!string || !string->string || !node || !node->arg || !w_p)
    return (NULL);
  len = my_strlen(node->arg);
  if (node->type == INTEGER_POS_WITH_PLUS)
    {
      if (w_p->width > 0)
	w_p->width = w_p->width - 1;
      string = add_elem_to_string(string, cursor, '+');
      cursor = cursor + 1;
    }
  prec = w_p->precision;
  while (prec)
    {
      string = add_elem_to_string(string, cursor, '0');
      prec = prec - 1;
      cursor = cursor + 1;
    }
  if ((string = insert_string(string, node->arg, cursor)) == NULL)
    return (NULL);
  cursor = cursor + len;
  while (w_p->width > w_p->precision + len)
    {
      string = add_elem_to_string(string, cursor, node->complete_width);
      w_p->width = w_p->width - 1;
      cursor = cursor + 1;
    }


  /* unsigned int		len; */

  /* if (!string || !string->string || !node || !node->arg) */
  /*   return (NULL); */
  /* len = my_strlen(node->arg); */
  /* if (node->type == INTEGER_POS_WITH_PLUS) */
  /*   { */
  /*     string = add_elem_to_string(string, cursor, '+'); */
  /*     cursor = cursor + 1; */
  /*   } */
  /* if (len > width) */
  /*   return (insert_string(string, node->arg, cursor)); */
  /* if ((string = insert_string(string, node->arg, cursor)) == NULL) */
  /*   return (NULL); */
  /* cursor = cursor + len; */
  /* while (len < width) */
  /*   { */
  /*     string = add_elem_to_string(string, cursor, node->complete_width); */
  /*     width = width - 1; */
  /*   } */
  return (string);
}
