/*
** flag_string.c for flag_string in /home/vuille_f/PSU_2015_my_printf/flag_fct
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov 11 11:15:53 2015 Florian Vuillemot
** Last update Thu Nov 12 01:53:28 2015 Florian Vuillemot
*/

#include		"flag_function.h"

void			get_flag_string(t_flag_with_fct *tab, unsigned int *nb)
{
  if (!tab || !nb)
    return ;
  tab[*nb].flag_fct = &flag_s_maj;
  tab[*nb].flag = my_strdup("S");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_s;
  tab[*nb].flag = my_strdup("s");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_c;
  tab[*nb].flag = my_strdup("c");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_c;
  tab[*nb].flag = my_strdup("hc");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_c;
  tab[*nb].flag = my_strdup("hhc");
  *nb = *nb + 1;
}

char			*flag_s(va_list *list, int *type)
{
  char			*res;

  if (!list || !type)
    return (NULL);
  *type = INTEGER_POS;
  if ((res = va_arg(list, char *)) == NULL)
    return (my_strdup("(null)"));
  if ((res = my_strdup(res)) == NULL)
    return (my_strdup("(null)"));
  return (res);
}


char			*flag_c(va_list *list, int *type)
{
  char			res[2];

  if (!list || !type)
    return (NULL);
  *type = CHARACTER;
  res[1] = '\0';
  res[0] = (char)va_arg(list, int);
  return (my_strdup(res));
}
