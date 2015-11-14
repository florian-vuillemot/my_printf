/*
** flag_d.c for flag_d in /home/vuille_f/PSU_2015_my_printf/fct_flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 15:36:19 2015 Florian Vuillemot
** Last update Sat Nov 14 16:14:57 2015 Florian Vuillemot
*/

#include		"flag_function.h"

void			get_flag_integer_long_short(t_flag_with_fct *tab,
						    unsigned int *nb)
{
  if (!tab || !nb)
    return ;
  tab[*nb].flag_fct = &flag_d;
  tab[*nb].flag = my_strdup("d");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_d;
  tab[*nb].flag = my_strdup("i");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_d;
  tab[*nb].flag = my_strdup("hd");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_ld;
  tab[*nb].flag = my_strdup("ld");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_lld;
  tab[*nb].flag = my_strdup("lld");
  *nb = *nb + 1;
}

char			*flag_d(va_list *list, int *type)
{
  int			res;

  if (!list)
    return (NULL);
  res = va_arg(list, int);
  if (res < 0)
    *type = INTEGER_MINUS;
  else
    *type = INTEGER_POS;
  return (my_putnbr_string((long int)res));
}

char			*flag_ld(va_list *list, int *type)
{
  long int		res;

  if (!list)
    return (NULL);
  res = va_arg(list, long int);
  if (res < 0)
    *type = INTEGER_MINUS;
  else
    *type = INTEGER_POS;
  return (my_putnbr_string(res));
}

char			*flag_lld(va_list *list, int *type)
{
  long long int		res;

  if (!list)
    return (NULL);
  res = va_arg(list, long long int);
  if (res < 0)
    *type = INTEGER_MINUS;
  else
    *type = INTEGER_POS;
  return (my_put_ll_nbr(res));
}
