/*
** pars.c for clean in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 17:40:39 2015 Florian Vuillemot
** Last update Thu Nov 12 09:28:42 2015 Florian Vuillemot
*/

#include		"pars.h"

t_string		*parse(char *str, t_flag *flag)
{
  t_string		*string;
  unsigned int		cursor;

  if (!str || !flag)
    return (NULL);
  if ((string = create_string(str)) == NULL)
    return (NULL);
  cursor = 0;
  while (string->string[cursor])
    {
      if (string->string[cursor] == '%')
	cursor = analyse_flag(string, cursor + 1, flag);
      else
	cursor = cursor + 1;
    }
  return (string);
}

unsigned int		analyse_flag(t_string *str,
				     unsigned int cursor,
				     t_flag *flag)
{
  int			is_flag;
  int			i;

  if (!str || !str->string || !flag)
    return (0);
  i = cursor;
  while (found_char_in_string(str->string[i], flag->autorized_with_flag))
    i = i + 1;
  i = clean_unnecessary_character(str, cursor, i, flag->autorized_with_flag);
  if ((is_flag = cmp_string_and_flag(flag, &str->string[i])) == -1)
    return (i + 1);
  return (i + my_strlen(flag->flag_and_fct[is_flag].flag));
}

unsigned int		clean_unnecessary_character(t_string *string,
						    unsigned int beg,
						    unsigned int end,
						    char *char_autorized)
{
  if (!string || !string->string)
    return (0);
  while (*char_autorized)
    {
      end = clean_one_char(string, beg, end, *char_autorized);
      char_autorized = char_autorized + 1;
    }
  end = remove_elem1_if_elem0(string, beg, end, "-0");
  end = remove_elem1_if_elem0(string, beg, end, "+ ");
  make_string_in_order(string, beg, end);
  return (end);
}

