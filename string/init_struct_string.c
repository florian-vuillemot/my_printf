/*
** init_struct_string.c for init string in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 14:39:12 2015 Florian Vuillemot
** Last update Sun Nov  8 21:01:25 2015 Florian Vuillemot
*/

#include		"struct_string.h"

static void		clear_string(t_string *string)
{
  unsigned int		i;

  i = string->cursor;
  while (i < string->len)
    {
      string->string[i] = '\0';
      i = i + 1;
    }
  string->string[i] = '\0';
}

t_string		*create_string(char *str)
{
  t_string		*string;
  unsigned int		len_str;

  if ((string = malloc(sizeof(*string) * 1)) == NULL)
    return (NULL);
  string->len = BUFSIZ;
  if ((string->string =
       malloc(sizeof(*string->string) * (1 + string->len))) == NULL)
    return (free_string(string));

  string->cursor = 0;
  len_str = my_strlen(str);
  while (string && string->len < len_str)
    string = realloc_string(string);
  if (!string)
    return (NULL);
  while ((string->string[string->cursor] = *str))
    {
      string->cursor = string->cursor + 1;
      str = str + 1;
    }
  clear_string(string);
  return (string);
}

t_string		*free_string(t_string *string)
{
  if (string)
    {
      if (string->string)
	free(string->string);
      free(string);
    }
  return (NULL);
}


t_string		*realloc_string(t_string *str_realloc)
{
  t_string		*new_string;

  if ((new_string = malloc(sizeof(*new_string) * 1)) == 0)
    return (NULL);
  new_string->len = BUFSIZ + str_realloc->len - 1;
  if ((new_string->string = malloc(sizeof(*new_string->string) *
			       (new_string->len + 1))) == NULL)
    {
      free_string(new_string);
      print_string(str_realloc);
      return (free_string(str_realloc));
    }
  new_string->string[new_string->len] = 0;
  new_string->cursor = 0;
  while ((new_string->string[new_string->cursor] =
	  str_realloc->string[new_string->cursor]))
    new_string->cursor = new_string->cursor + 1;
  free_string(str_realloc);
  clear_string(new_string);
  return (new_string);
}
