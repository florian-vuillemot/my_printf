/*
** string.h for string.h in /home/vuille_f/rendu/Piscine_C_evalexpr
**
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
**
** Started on  Wed Oct 21 09:59:41 2015 Florian Vuillemot
** Last update Mon Nov 16 22:58:01 2015 Florian Vuillemot
*/

#include "my_string.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  if (str == 0)
    return ;
  while (*str)
    {
      my_putchar(*str);
      str = str + 1;
    }
}

unsigned int	my_strlen(char *str)
{
  char		*cursor;

  if (str == 0)
    return (0);
  cursor = str;
  while (*cursor)
    cursor = cursor + 1;
  return (cursor - str);
}

char		*my_strdup(char *str)
{
  char		*result;
  unsigned int	length;

  if (!str || (length = my_strlen(str)) == 0)
    return (0);
  if ((result = malloc(sizeof(char) * (length + 1))) == 0)
    return (0);
  while ((*result = *str))
    {
      str = str + 1;
      result = result + 1;
    }
  return (result - length);
}

char		*m_strdup(const char *str)
{
  char		*result;
  unsigned int	size;

  if (!str)
    return (NULL);
  size = 0;
  while (str[size])
    size++;
  if ((result = malloc(sizeof(char) * (size + 1))) == 0)
    return (0);
  result[size] = '\0';
  size = 0;
  while ((result[size] = str[size]))
    size++;
  return (result);
}
