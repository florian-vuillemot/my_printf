/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Thu Nov 12 01:56:17 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

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

t_string		*get_width_prec_string(t_string *str,
					       t_width_prec *w_p,
					       unsigned int cursor,
					       t_node_va_arg *node)
{
  unsigned int		len;

  if (!str || !str->string || !node || !node->arg || !w_p)
    return (NULL);
  len = my_strlen(node->arg);
  while (w_p->width > len)
    str = add_elem_on_get_width_precision(str, &cursor,
					  node->complete_width, &w_p->width);
  return (insert_string(str, node->arg, cursor));
}

t_string		*get_width_prec_string_minus(t_string *string,
						     t_width_prec *w_p,
						     unsigned int cur,
						     t_node_va_arg *nd)
{
  unsigned int		len;

  if (!string || !string->string || !nd || !nd->arg || !w_p)
    return (NULL);
  len = my_strlen(nd->arg);
  if ((string = insert_string(string, nd->arg, cur)) == NULL)
    return (NULL);
  cur = cur + len;
  while (w_p->width > len)
    string = add_elem_on_get_width_precision(string, &cur,
					     nd->complete_width, &w_p->width);
  return (string);
}
