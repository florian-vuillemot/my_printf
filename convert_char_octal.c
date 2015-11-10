/*
** convert_char_octal.c for  in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 20:39:21 2015 Florian Vuillemot
** Last update Tue Nov 10 21:05:48 2015 Florian Vuillemot
*/

#include "my_string.h"
#include "struct_string.h"

static char		char_to_octal(char convert, int curs)
{
  unsigned int		end;
  unsigned int		res;
  unsigned int		one;
  unsigned int		pow;

  one = 1;
  end = curs + 3;
  res = 0;
  pow = 1;
  while (curs < end && curs < sizeof(char) * 8)
    {
      if (one & (convert << curs))
	res = pow + res;
      pow = pow * 2;
      curs = curs + 1;
    }
  return ("01234567"[res]);
}

t_string		*convert_char_octal(t_string *string, char convert,
					    unsigned int *cursor)
{
  int			curs;

  if (!string || !string->string)
    return (NULL);
  curs = 0;
  if (string->len < *cursor + 4)
    if ((string = realloc_string(string)) == NULL)
      return (NULL);
  string =
    add_elem_to_string(string, *cursor, '\\');
  *cursor = *cursor + 1;
  curs = sizeof(char) * 8 - 3;
  while (curs > -1)
    {
      string =
	add_elem_to_string(string, *cursor, char_to_octal(convert, curs));
      curs = curs - 3;
      *cursor = *cursor + 1;
    }
  return (string);
}


int main()
{
  t_string *string;
  unsigned int i;

  i = 0;
  string = create_string("coucou");
  printf("string : %s\n",string->string);
  string = convert_char_octal(string, 34, &i);
  printf("string : %s\n",string->string);
  return (0);
}
