/*
** get_elem_to_print.h for get in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 10:30:16 2015 Florian Vuillemot
** Last update Tue Nov 10 09:37:00 2015 Florian Vuillemot
*/

#include		"get_elem_to_print.h"

t_string		*get_elem_to_print(t_string *string, t_flag *flag,
					   t_list_va_arg *list)
{
  unsigned int		cursor;
  int			ind;

  if (!string || !list)
    return (NULL);
  cursor = 0;
  while (string->string[cursor])
    {
      if (string->string[cursor] == '%')
	{
	  if ((ind = contain_flag_fct(flag, string->string + cursor + 1)) > 0)
	    {
	      string = remove_elem_to_string(string, cursor);
	      if ((string = get_flag_character(string, cursor, list, flag))
		  == NULL)
		return (NULL);
	      //	      printf("%s\n",string->string + cursor);
	      /* ind = my_strlen(flag->flag_and_fct->flag); */
	      /* while ((ind = ind - 1) > -1) */
	      /* 	string = remove_elem_to_string(string, cursor); */
	    }
	}
      cursor = cursor + 1;
    }
  return (string);
}
