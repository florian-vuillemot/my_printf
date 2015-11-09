/*
** string.h for string.h in /home/vuille_f/rendu/Piscine_C_evalexpr
**
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
**
** Started on  Wed Oct 21 09:59:41 2015 Florian Vuillemot
** Last update Sun Nov  8 10:48:37 2015 Florian Vuillemot
*/

#include "my_string.h"

int		my_strcmp(char *str1, char *str2)
{
  if (!str1 || !str2)
    return (-1);
  while (*str1 && *str1 == *str2)
    {
      str1 = str1 + 1;
      str2 = str2 + 1;
    }
  if (!*str1 && !*str2)
    return (1);
  return (0);
}

int		found_char_in_string(char character, char *string)
{
  if (!string)
    return (-1);
  while (*string && *string != character)
    string = string + 1;
  if (*string)
    return (1);
  return (0);
}

int		get_place_char_in_string(char character, char *string)
{
  char		*beg;

  if (!string)
    return (-1);
  beg = string;
  while (*string && *string != character)
    string = string + 1;
  if (*string)
    return (string - beg);
  return (-1);
}
