/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Fri Nov 13 09:17:01 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

static t_string		*add_0x_to_pnt(t_string *str, unsigned int *cursor)
{
  if (!str || !cursor)
    return (NULL);
  str = add_elem_to_string(str, *cursor, '0');
  *cursor = *cursor + 1;
  str = add_elem_to_string(str, *cursor, 'x');
  *cursor = *cursor + 1;
  return (str);
}

static t_string		*complete_string(t_string *str,
					 t_width_prec *w_and_prec,
					 unsigned int cursor,
					 t_node_va_arg *node)
{
  if (!str || !w_and_prec || !node)
    return (NULL);
  if (node->type == INTEGER_POS_WITH_PLUS && node->complete_width != '0')
    {
      str = add_elem_to_string(str, cursor, '+');
      cursor++;
    }
  if (node->complete_width != '0')
    str = add_0x_to_pnt(str, &cursor);
  while (w_and_prec->precision--)
    {
      str = add_elem_to_string(str, cursor, '0');
      cursor++;
    }
  return (insert_string(str, node->arg, cursor));
}

t_string		*get_width_prec_pnt_convert(t_string *str,
						    t_width_prec *w_and_prec,
						    unsigned int cursor,
						    t_node_va_arg *node)
{
  unsigned int		len;

  if (!str || !str->string || !node || !node->arg || !w_and_prec)
    return (NULL);
  len = my_strlen(node->arg) + 2;
  if (w_and_prec->precision > 0)
    node->complete_width = ' ';
  if (node->type == INTEGER_POS_WITH_PLUS && node->complete_width != '0')
    len++;
  if (node->type == INTEGER_POS_WITH_PLUS && node->complete_width == '0')
    {
      if (w_and_prec->width > 0)
	w_and_prec->width--;
      str = add_elem_to_string(str, cursor++, '+');
    }
  if (node->complete_width == '0')
    str = add_0x_to_pnt(str, &cursor);
  while (w_and_prec->width-- > w_and_prec->precision + len)
    str = add_elem_to_string(str, cursor++, node->complete_width);
  return (complete_string(str, w_and_prec, cursor, node));
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

t_string		*get_width_prec_pnt_convert_minus(t_string *string,
							  t_width_prec *w_p,
							  unsigned int cur,
							  t_node_va_arg *nd)
{
  unsigned int		len;
  unsigned int		prec;

  if (!string || !string->string || !nd || !nd->arg || !w_p)
    return (NULL);
  if (nd->type == INTEGER_POS_WITH_PLUS && w_p->width > 0)
    w_p->width = w_p->width - 1;
  len = my_strlen(nd->arg) + 2;
  if (nd->type == INTEGER_POS_WITH_PLUS)
    string = add_elem_to_string(string, cur++, '+');
  string = add_elem_to_string(string, cur++, '0');
  string = add_elem_to_string(string, cur++, 'x');
  prec = w_p->precision;
  while (prec)
    string = add_elem_on_get_width_precision(string, &cur, '0', &prec);
  if ((string = insert_string(string, nd->arg, cur)) == NULL)
    return (NULL);
  cur = cur + len - 2;
  while (w_p->width > w_p->precision + len)
      string = add_elem_on_get_width_precision(string, &cur,
					       nd->complete_width,
					       &w_p->width);
  return (string);
}
