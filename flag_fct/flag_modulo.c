/*
** flag_string.c for flag_string in /home/vuille_f/PSU_2015_my_printf/flag_fct
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov 11 11:15:53 2015 Florian Vuillemot
** Last update Sat Nov 14 10:13:32 2015 Florian Vuillemot
*/

#include		"flag_function.h"

void			get_flag_m(t_flag_with_fct *tab, unsigned int *nb)
{
  if (!tab || !nb)
    return ;
  tab[*nb].flag_fct = &flag_modulo;
  tab[*nb].flag = my_strdup("%");
  *nb = *nb + 1;
}

char			*flag_modulo(va_list *list, int *type)
{
  char			*res;

  if (!list || !type)
    return (NULL);
  *type = NO_TYPE;
  return (res = my_strdup("%"));
}
