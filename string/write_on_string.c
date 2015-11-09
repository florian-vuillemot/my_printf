/*
** write_on_string.c for write in /home/vuille_f/PSU_2015_my_printf/string
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 15:27:20 2015 Florian Vuillemot
** Last update Sun Nov  8 21:16:16 2015 Florian Vuillemot
*/

#include		"struct_string.h"

t_string		*conca_string(t_string *string, t_string *copy_str)
{
  if (!copy_str || !copy_str->string || (string && !string->string))
    return (NULL);
  if (!string)
    return (create_string(copy_str->string));
  while (string && string->len < copy_str->cursor + string->cursor)
    string = realloc_string(string);
  if (!string)
    return (free_string(copy_str));
  copy_str->cursor = 0;
  while ((string->string[string->cursor] = copy_str->string[copy_str->cursor]))
    {
      string->cursor = string->cursor + 1;
      copy_str->cursor = copy_str->cursor + 1;
    }
  return (string);
}

t_string		*add_string(t_string *string, char *copy)
{
  unsigned int		len_copy;

  if (!copy || (string && !string->string))
    return (NULL);
  if (!string)
    return (create_string(copy));
  len_copy = my_strlen(copy);
  while (string && string->len < string->cursor + len_copy)
    string = realloc_string(string);
  if (!string)
    return (NULL);
  while ((string->string[string->cursor] = *copy))
    {
      string->cursor = string->cursor + 1;
      copy = copy + 1;
    }
  return (string);
}

t_string		*insert_string(t_string *string, char *str,
				       unsigned int place)
{
  unsigned int		len;

  if (!str || (string && !string->string))
    return (NULL);
  if (!string)
    return (create_string(str));
  len = my_strlen(str);
  while (string->len < string->cursor + len || string->len < place)
    if ((string = realloc_string(string)) == NULL)
      return (NULL);
  while (*str)
    {
      if ((string = add_elem_to_string(string, place, *str)) == NULL)
	return (NULL);
      place = place + 1;
      str = str + 1;
    }
  return (string);
}
