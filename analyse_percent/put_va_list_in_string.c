/*
** analyse_percent.c for analyse in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov  8 11:38:43 2015 Florian Vuillemot
** Last update Sun Nov  8 12:59:09 2015 Florian Vuillemot
*/

#include		"analyse_percent.h"

unsigned int		put_va_list_in_string(t_string *string,
					      char *(*fct)(va_list *),
					      unsigned int cursor,
					      va_list *list)
{
  int			precision;
  t_string		*add_string;

  /* récupère la précision */
  precision = get_precision(string, cursor);
  /*
  add_string = NULL;
  add_string = fct(list); récupère l'argument sous la bonne forme
  récupére 
//  add_string = get_elem(string, cursor, precision, va_list);
  precision = get_length(string, cursor);
  récupére la bonne taille du string
  add_string = get_elem_with_good_size(add_string, precision,
				       get_drapea(string, cursor));
  on concatène les deux chaines
  string = add_string_at_curs(string, add_string);
  precision = add_string->cursor;
  free_string(add_string);
  */
  return (cursor + precision);
}
