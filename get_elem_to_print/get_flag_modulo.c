/*
** get_attribut.c for  in /home/vuille_f/PSU_2015_my_printf/get_elem_to_print
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 11:12:42 2015 Florian Vuillemot
** Last update Sat Nov 14 18:42:36 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

t_string		*get_flag_modulo(t_string *string,
					 unsigned int *cursor,
					 t_list_va_arg *list)
{
  if (!list || !string || !list->cursor || !string->string || !cursor)
    return (NULL);
  while (string &&
  	 string->string[*cursor] && string->string[*cursor] != '%')
    string = remove_elem_to_string(string, *cursor);
  get_arg(list);
  return (string);
}
