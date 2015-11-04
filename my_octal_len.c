/*
** my_octal_len.c for thanks norm ! in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 23:04:23 2015 Florian Vuillemot
** Last update Wed Nov  4 23:06:36 2015 Florian Vuillemot
*/

#include	"my_string.h"

int		my_octal_len(char *str)
{
  int		curs;

  curs = 0;
  while (*str)
    {
      if (*str < 32 && *str >= 127)
	curs = curs + 4;
      else
	curs = curs + 1;
      str = str + 1;
    }
  return (curs);
}
