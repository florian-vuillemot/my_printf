/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Mon Nov  9 19:18:30 2015 Florian Vuillemot
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

t_string		*get_flag_integer(t_string *string,
					  unsigned int *cursor,
					  int type_flag,
					  t_list_va_arg *list)
{
  int			minus;
  t_node_va_arg		*node;
  unsigned int		width;

  if (!list || !string || !list->cursor || !string->string)
    return (NULL);
  node = list->cursor;
  get_arg(list);
  minus = 0;
  while (string->string[*cursor] == '#' || string->string[*cursor] == ' ')
    string = remove_elem_to_string(string, *cursor);
  if (string->string[*cursor] == '+')
    {
      if (node->type == INTEGER_POS)
	*cursor = *cursor + 1;
      else
	string = remove_elem_to_string(string, *cursor);

    }
  if (string->string[*cursor] == '-')
    {
      minus = 1;
      string = remove_elem_to_string(string, *cursor);
    }
  width = get_field_width(string, *cursor);
  get_precision(string, *cursor, node);
  string = remove_elem_to_string(string, *cursor);
  if (minus)
    return (get_width_precision_string_minus(string, width, *cursor, node));
  return (get_width_precision_string(string, width, *cursor, node));
}

t_string		*get_width_precision_string(t_string *string,
						    unsigned int width,
						    unsigned int cursor,
						    t_node_va_arg *node)
{
  unsigned int		len;

  if (!string || !string->string || !node || !node->arg)
    return (NULL);
  len = my_strlen(node->arg);
  if (len < width)
    return (insert_string(string, node->arg, cursor));
  while (len < width)
    {
      add_elem_to_string(string, cursor, ' ');
      width = width - 1;
      cursor = cursor + 1;
    }
  return (insert_string(string, node->arg, cursor));
}


t_string		*get_width_precision_string_minus(t_string *string,
							  unsigned int width,
							  unsigned int cursor,
							  t_node_va_arg *node)
{
  unsigned int		len;

  if (!string || !string->string || !node || !node->arg)
    return (NULL);
  len = my_strlen(node->arg);
  if (len < width)
    return (insert_string(string, node->arg, cursor));
  if ((insert_string(string, node->arg, cursor)) == NULL)
    return (NULL);
  cursor = cursor + len;
  while (len < width)
    {
      add_elem_to_string(string, cursor, ' ');
      width = width - 1;
    }
  return (string);
}
