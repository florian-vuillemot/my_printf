/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Sat Nov 14 09:00:13 2015 Florian Vuillemot
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
  if (found_char_in_string(flag->flag_and_fct[nb_fg].flag[0], TYPE_INTEGER))
    {
      if (flag->flag_and_fct[nb_fg].flag[0] == 'o' ||
	  flag->flag_and_fct[nb_fg].flag[0] == 'x' ||
	  flag->flag_and_fct[nb_fg].flag[0] == 'X' ||
	  flag->flag_and_fct[nb_fg].flag[0] == 'b')
	return (get_flag_integer_and_convert(string, &cursor, list));
      if (flag->flag_and_fct[nb_fg].flag[0] == 'l')
	return (get_flag_long(string, &cursor, list));
      return (get_flag_integer(string, &cursor, list));
    }
  if (flag->flag_and_fct[nb_fg].flag[0] == 'p')
    return (get_flag_pnt(string, &cursor, list));
  return (get_with_flag_string(string, &cursor, list));
}

t_string		*clean_string_and_get_data(t_string *string,
						   unsigned int *cursor,
						   unsigned int *minus,
						   t_node_va_arg *node)
{
  if (!string || !node || !cursor || !minus)
    return (NULL);
  *minus = 0;
  if (string->string[*cursor] == '#')
    string = remove_elem_to_string(string, *cursor);
  if (string->string[*cursor] == ' ' && (*minus = 2))
    string = remove_elem_to_string(string, *cursor);
  if (string->string[*cursor] == '+')
    {
      if (node->type == INTEGER_POS)
	node->type = INTEGER_POS_WITH_PLUS;
      string = remove_elem_to_string(string, *cursor);
    }
  if (string->string[*cursor] == '-' && (*minus = *minus + 1))
    {
      string = remove_elem_to_string(string, *cursor);
      node->complete_width = ' ';
    }
 if (string->string[*cursor] == '0' && (node->complete_width = '0'))
    string = remove_elem_to_string(string, *cursor);
  return (string);
}

t_string		*clean_string_data_string(t_string *string,
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
    string = remove_elem_to_string(string, *cursor);
  if (string->string[*cursor] == '+')
    {
      if (node->type == INTEGER_POS)
	node->type = INTEGER_POS_WITH_PLUS;
      string = remove_elem_to_string(string, *cursor);
    }
  if (string->string[*cursor] == '-' && (*minus = *minus + 1))
    {
      string = remove_elem_to_string(string, *cursor);
      node->complete_width = ' ';
    }
  else if (string->string[*cursor] == '0' && (node->complete_width = ' '))
    string = remove_elem_to_string(string, *cursor);
  return (string);
}

static t_string		*choice_node_type_to_convert(t_string *string,
						     unsigned int *cursor,
						     t_node_va_arg *node)
{
  if (!string || !string->string || !cursor || !node)
    return (NULL);
  if (string->string[*cursor] == '#')
    {
      if (node->type == CONVERT_MAJ)
	node->type = PRINT_HEXA_0X;
      if (node->type == CONVERT_MIN)
	node->type = PRINT_HEXA_0;
      if (node->type == OCTAL)
	node->type = PRINT_OCTAL_0;
      string = remove_elem_to_string(string, *cursor);
    }
  return (string);
}

t_string		*clean_string_data_convert(t_string *string,
						   unsigned int *cursor,
						   unsigned int *minus,
						   t_node_va_arg *node)
{
  if (!string || !node || !cursor || !minus)
    return (NULL);
  *minus = 0;
  if ((string = choice_node_type_to_convert(string, cursor, node))
      == NULL)
    return (NULL);
  if (string->string[*cursor] == ' ')
    string = remove_elem_to_string(string, *cursor);
  if (string->string[*cursor] == '+')
    {
      string = remove_elem_to_string(string, *cursor);
      *minus = 2;
    }
  if (string->string[*cursor] == '-' && (*minus = *minus + 1))
    {
      string = remove_elem_to_string(string, *cursor);
      node->complete_width = ' ';
    }
  else if (string->string[*cursor] == '0' && (node->complete_width = '0'))
    string = remove_elem_to_string(string, *cursor);
  return (string);
}
