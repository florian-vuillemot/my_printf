/*
** get_elem_to_print.h for get in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 10:30:16 2015 Florian Vuillemot
** Last update Mon Nov  9 17:13:08 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

t_string		*get_elem_to_print(t_string *string, t_flag *flag,
					   t_list_va_arg *list)
{
  unsigned int		cursor;
  int			index_list;

  if (!string || !list)
    return (NULL);
  cursor = 0;
  index_list = 0;
  while (string->string[cursor])
    {
      if (string->string[cursor] == '%')
	{
	  if (contain_flag_fct(flag, string->string + cursor + 1) > 0)
	    {

	      /*
bug
	       */
	      string = remove_elem_to_string(string, cursor);
	      if ((string = get_flag_character(string, cursor, list, flag))
		  == NULL)
		return (NULL);
	    }
	}
      cursor = cursor + 1;
    }
  return (string);
}
