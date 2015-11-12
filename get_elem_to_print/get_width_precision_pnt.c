/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Thu Nov 12 14:31:11 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

static t_string		*add_elem_on_get_width_precision(t_string *string,
							 unsigned int *cursor,
							 char elem_to_add,
							 unsigned int *w_prec)
{
  string = add_elem_to_string(string, *cursor, elem_to_add);
  if (*w_prec > 0)
    *w_prec = *w_prec - 1;
  *cursor = *cursor + 1;
  return (string);
}

static t_string		 *put_flag_character(t_string *str,
					     unsigned int *cursor,
					     t_node_va_arg *node,
					     unsigned int *len)
{
  if (!str || !node)
    return (NULL);
  if (node->type == INTEGER_POS_WITH_PLUS)
    {
      *len = *len + 1;
      if ((str = add_elem_to_string(str, *cursor, '+')) == NULL)
	return (NULL);
      *cursor = *cursor + 1;
    }
  return (str);
}

t_string		*get_width_prec_pnt_convert(t_string *str,
						    t_width_prec *w_and_prec,
						    unsigned int cursor,
						    t_node_va_arg *node)
{
  unsigned int		len;

  if (!str || !str->string || !node || !node->arg || !w_and_prec)
    return (NULL);
  len = my_strlen(node->arg);
  if (node->type == INTEGER_POS_WITH_PLUS && w_and_prec->width > 0)
    w_and_prec->width = w_and_prec->width - 1;
  if (w_and_prec->width > 0)
    w_and_prec->width = w_and_prec->width - 1;
  if (w_and_prec->width > 0)
    w_and_prec->width = w_and_prec->width - 1;
  if (node->complete_width == '0')
    {
      w_and_prec->width = w_and_prec->width + 2;
      str = put_flag_character(str, &cursor, node, &w_and_prec->width);
      str = add_elem_on_get_width_precision(str, &cursor, '0', &w_and_prec->width);
      str = add_elem_on_get_width_precision(str, &cursor, 'x', &w_and_prec->width);  
    }
  while (w_and_prec->width > w_and_prec->precision + len)
    {
      str = add_elem_to_string(str, cursor, node->complete_width);
      w_and_prec->width = w_and_prec->width - 1;
      cursor = cursor + 1;
    }
  if (node->complete_width != '0')
    {
      str = put_flag_character(str, &cursor, node, &w_and_prec->width);
      w_and_prec->width = w_and_prec->width + 2;
      str = add_elem_on_get_width_precision(str, &cursor, '0', &w_and_prec->width);
      str = add_elem_on_get_width_precision(str, &cursor, 'x', &w_and_prec->width);  
    }
  while (w_and_prec->precision && (str = add_elem_to_string(str, cursor, '0')))
    {
      w_and_prec->precision = w_and_prec->precision - 1;
      cursor = cursor + 1;
    }
  return (insert_string(str, node->arg, cursor));
}

static void		get_precision_convert_minus(t_node_va_arg *nd,
						   t_width_prec *w_p,
						   unsigned int *prec)
{
  if (!nd || !w_p || !prec)
    return ;
  *prec = w_p->precision;
  if (nd->type > 0)
    {
      if (nd->type != PRINT_OCTAL)
  	{
  	  if (w_p->width > 0)
  	    w_p->width = w_p->width - 1;
  	  *prec = w_p->precision + 2;
  	}
      else
      	*prec = w_p->precision + 1;
      if (w_p->width > 0)
  	w_p->width = w_p->width - 1;
    }
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
  len = my_strlen(nd->arg);
  get_precision_convert_minus(nd, w_p, &prec);
  string = put_flag_character(string, &cur, nd, &prec);
  string = add_elem_on_get_width_precision(string, &cur, '0', &prec);
  string = add_elem_on_get_width_precision(string, &cur, 'x', &prec);
  len = len + 2;
  while (prec)
    string = add_elem_on_get_width_precision(string, &cur, '0', &prec);
  if ((string = insert_string(string, nd->arg, cur)) == NULL)
    return (NULL);
  cur = cur + len;
  while (w_p->width > w_p->precision + len)
    string = add_elem_on_get_width_precision(string, &cur,
  					     nd->complete_width, &w_p->width);
  return (string);
}
