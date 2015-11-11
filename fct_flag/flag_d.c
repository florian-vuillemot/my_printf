/*
** flag_d.c for flag_d in /home/vuille_f/PSU_2015_my_printf/fct_flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 15:36:19 2015 Florian Vuillemot
** Last update Tue Nov 10 17:17:46 2015 Florian Vuillemot
*/

#include		"flag_function.h"

char			*flag_d(va_list *list, int *type)
{
  int			res;

  if (!list)
    return (NULL);
  res = va_arg(list, int);
  return (my_putnbr_string((long int)res));
}