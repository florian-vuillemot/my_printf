/*
** flag_p.c for flag_p in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov 11 08:44:01 2015 Florian Vuillemot
** Last update Thu Nov 12 11:33:07 2015 Florian Vuillemot
*/

#include		"flag_function.h"

void			get_flag_p(t_flag_with_fct *tab, unsigned int *nb)
{
  if (!tab || !nb)
    return ;
  tab[*nb].flag_fct = &flag_p;
  tab[*nb].flag = my_strdup("p");
  *nb = *nb + 1;
}

char			*flag_p(va_list *list, int *type)
{
  void			*pnt;
  char			*hexa;

  if (!list || !type)
    return (NULL);
  *type = INTEGER_POS;
  if ((pnt = va_arg(list, void *)) == NULL)
    return (my_strdup("(nil)"));
  if ((hexa =
       convert_hexa((unsigned long int)pnt, "0123456789abcdef")) == NULL)
    return (my_strdup("(nil)"));
  return (hexa);
}
