/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Fri Nov 13 23:16:11 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

static t_string		*print_hexa_octal(t_string *str,
					   t_width_prec *w_and_prec,
					   unsigned int *cursor,
					   t_node_va_arg *node)
{
  if (!str || !w_and_prec || !node)
    return (NULL);
  if (node->type == PRINT_HEXA_0X || node->type == PRINT_HEXA_0)
    {
      str = add_elem_to_string(str, (*cursor)++, '0');
      if (node->type == PRINT_HEXA_0X)
	str = add_elem_to_string(str, (*cursor)++, 'X');
      else
	str = add_elem_to_string(str, (*cursor)++, 'x');
    }
  if (node->type == PRINT_OCTAL_0)
    str = add_elem_to_string(str, (*cursor)++, '0');
  return (str);
}

t_string		*get_width_prec_str_convert(t_string *str,
						    t_width_prec *w_and_prec,
						    unsigned int cursor,
						    t_node_va_arg *node)
{
  unsigned int		len;

  if (!str || !str->string || !node || !node->arg || !w_and_prec)
    return (NULL);
  len = my_strlen(node->arg);
  if (node->type > PRINT_H_O)
    len = len + (node->type == PRINT_OCTAL_0 ? 1 : 2);
  if (node->type == PRINT_OCTAL_0 && w_and_prec->precision)
    w_and_prec->precision--;
  if (w_and_prec->precision == 0 && node->complete_width == '0')
    str = print_hexa_octal(str, w_and_prec, &cursor, node);
  while (w_and_prec->width-- > w_and_prec->precision + len)
    if (w_and_prec->precision && node->complete_width == '0')
      str = add_elem_to_string(str, cursor++, ' ');
    else
      str = add_elem_to_string(str, cursor++, node->complete_width);
  if (w_and_prec->precision || node->complete_width != '0')
    str = print_hexa_octal(str, w_and_prec, &cursor, node);
  while (w_and_prec->precision--)
    str = add_elem_to_string(str, cursor++, '0');
  return (insert_string(str, node->arg, cursor));
}

static t_string		*add_elem_on_get_width_precision(t_string *string,
							 unsigned int *cursor,
							 char elem_to_add,
							 unsigned int *w_prec)
{
  string = add_elem_to_string(string, *cursor, elem_to_add);
  *w_prec = *w_prec - 1;
  *cursor = *cursor + 1;
  return (string);
}

t_string		*get_width_prec_convert_minus(t_string *string,
						      t_width_prec *w_p,
						      unsigned int cur,
						      t_node_va_arg *nd)
{
  unsigned int		len;
  unsigned int		prec;

  if (!string || !string->string || !nd || !nd->arg || !w_p)
    return (NULL);
  len = my_strlen(nd->arg);
  string = print_hexa_octal(string, w_p, &cur, nd);
  if (nd->type == PRINT_OCTAL_0 && w_p->precision)
    w_p->precision--;
  prec = w_p->precision;
  while (prec)
    string = add_elem_on_get_width_precision(string, &cur, '0', &prec);
  if ((string = insert_string(string, nd->arg, cur)) == NULL)
    return (NULL);
  cur = cur + len;
  if (nd->type > PRINT_H_O)
    len = len + (nd->type == PRINT_OCTAL_0 ? 1 : 2);
  while (w_p->width > w_p->precision + len)
    string = add_elem_on_get_width_precision(string, &cur,
					     nd->complete_width, &w_p->width);
  return (string);
}
