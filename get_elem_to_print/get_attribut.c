/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Tue Nov 10 15:24:10 2015 Florian Vuillemot
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
      if (flag->flag_and_fct[nb_fg].flag[0] == 'i' ||
	  flag->flag_and_fct[nb_fg].flag[0] == 'u' ||
	  flag->flag_and_fct[nb_fg].flag[0] == 'd')
	return (get_flag_integer(string, &cursor, nb_fg, list));
      //  return (get_flag_integer_and_convert(string, cursor, nb_fg, list));
    }
  //  return (get_flag_string(string, cursor, nb_fg, list));
  return (NULL);
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
  else if (string->string[*cursor] == '0' && (node->complete_width = '0'))
    string = remove_elem_to_string(string, *cursor);
  return (string);
}
