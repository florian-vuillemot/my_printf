/*
** mouv_elem_string.c for mouve elem string in /home/vuille_f/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 16:41:02 2015 Florian Vuillemot
** Last update Sun Nov  8 21:13:44 2015 Florian Vuillemot
*/

#include		"struct_string.h"

t_string		*add_elem_to_string(t_string *string,
					    unsigned int place,
					    char new_elem)
{
  char			swap;

  if (!string || !string->string)
    return (NULL);
  while (string && (string->len < string->cursor + 1 ||
		    string->len < place + 1))
    string = realloc_string(string);
  if (!string)
    return (NULL);
  if (string->cursor >= place)
    string->cursor = string->cursor + 1;
  while (string->string[place])
    {
      swap = string->string[place];
      string->string[place] = new_elem;
      new_elem = swap;
      place = place + 1;
    }
  string->string[place] = new_elem;
  string->string[place + 1] = '\0';
  return (string);
}

t_string		*remove_elem_to_string(t_string *string,
					      unsigned int place)
{
  if (!string || !string->string)
    return (NULL);
  if (place >= string->cursor)
    return (string);
  while ((string->string[place] = string->string[place + 1]))
    place = place + 1;
  string->cursor = string->cursor - 1;
  return (string);
}
