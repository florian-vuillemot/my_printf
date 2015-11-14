/*
** replace_star_and_dollar.c for  in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov 14 13:07:45 2015 Florian Vuillemot
** Last update Sat Nov 14 16:01:17 2015 Florian Vuillemot
*/

#include		"list_va_arg.h"

static t_string		*check_dollar(t_string *string, va_list *list,
				      unsigned int cur)
{
  int			nb;
  char			*str;
  int			i;

  if (!string || !list)
    return (NULL);
  if ((nb = my_getnbr(string->string + i)) < 0)
    return (string);
  i = -1;
  while (++i < nb)
    va_arg(list, int);
  /* if ((str = get_index_arg(arg, nb)) == NULL) */
  /*   return (string); */
  if ((string = insert_string(string, str, cur)) == NULL)
    return (NULL);
  cur += my_strlen(str);
  while (string && ((string->string[cur] <= '9' && string->string[cur] >= '0')
		    || string->string[cur] == '$'))
    string = remove_elem_to_string(string, cur);
  if (string && (found_char_in_string(string->string[cur], TYPE_L_S_P) ||
		 found_char_in_string(string->string[cur], TYPE_INTEGER)))
    {
      while (string && found_char_in_string(string->string[cur], TYPE_L_S_P))
	string = remove_elem_to_string(string, cur);
      while (string && found_char_in_string(string->string[cur], TYPE_INTEGER))
	string = remove_elem_to_string(string, cur);
    }
  else
    while (string && found_char_in_string(string->string[cur], "sSc"))
      string = remove_elem_to_string(string, cur);
  return (string);
}

t_string		*replace_star_and_dollar(t_string *string,
						 va_list *list)
{
  unsigned int		i;
  unsigned int		j;
  unsigned int		nb;

  if (!string || !list)
    return (NULL);
  i = 0;
  nb = 0;
  while (string && string->string[i])
    {
      if (string->string[i] == '%')
	{
	  nb++;
	  j = 1;
	  while (string->string[i + j] <= '9' && string->string[i + j] >= '0')
	    j++;
	  if (j > 1 && string->string[i + j] == '$')
	    {
	      string = remove_elem_to_string(string, i);
	      string = check_dollar(string, list, i);
	    }
	}
      i++;
    }
  return (string);
}
