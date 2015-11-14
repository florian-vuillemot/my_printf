/*
** convert_char_octal.c for  in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 20:39:21 2015 Florian Vuillemot
** Last update Sat Nov 14 08:34:30 2015 Florian Vuillemot
*/

#include "flag_function.h"

static char		char_to_octal(char convert, int curs)
{
  int			end;
  int			res;
  char			one;
  int			pow;

  one = 1;
  end = curs + 3;
  res = 0;
  pow = 1;
  while (curs < end && curs < (int)sizeof(char) * 8)
    {
      if (convert & (one << curs))
	res = pow + res;
      pow = pow * 2;
      curs = curs + 1;
    }
  return ("01234567"[res]);
}

t_string		*convert_char_octal(t_string *string, char convert,
					    unsigned int cursor)
{
  int			curs;

  if (!string || !string->string)
    return (NULL);
  if (string->len < cursor + 4)
    if ((string = realloc_string(string)) == NULL)
      return (NULL);
  string = add_elem_to_string(string, cursor, '\\');
  cursor = cursor + 1;
  curs = 0;
  while (curs < (int)sizeof(char) * 8)
    {
      string =
	add_elem_to_string(string, cursor, char_to_octal(convert, curs));
      curs = curs + 3;
    }
  cursor = cursor + 3;
  return (string);
}

char			*flag_s_maj(va_list *list, int *type)
{
  t_string		*string;
  char			*res;
  int			curs;
  char			convert;

  if (!list || !type)
    return (NULL);
  *type = ALL_CHAR;
  if ((res = va_arg(list, char *)) == NULL ||
      (string = create_string(res)) == NULL)
    return (my_strdup("(null)"));
  curs = -1;
  while (string->string[++curs])
    if (string->string[curs] < 32 || string->string[curs] >= 127)
      {
	convert = string->string[curs];
	string = remove_elem_to_string(string, curs);
	if (convert_char_octal(string, convert, curs) == NULL)
	  return (NULL);
      }
  res = my_strdup(string->string);
  free_string(string);
  return (res);
}
