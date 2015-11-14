/*
** flag_d.c for flag_d in /home/vuille_f/PSU_2015_my_printf/fct_flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 15:36:19 2015 Florian Vuillemot
** Last update Sat Nov 14 11:28:21 2015 Florian Vuillemot
*/

#include			"flag_function.h"

void				get_flag_unsigned_long_short(t_flag_with_fct
							     *tab,
							     unsigned int *nb)
{
  if (!tab || !nb)
    return ;
  tab[*nb].flag_fct = &flag_u;
  tab[*nb].flag = my_strdup("u");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_lu;
  tab[*nb].flag = my_strdup("lu");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_llu;
  tab[*nb].flag = my_strdup("llu");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_hu;
  tab[*nb].flag = my_strdup("hu");
  *nb = *nb + 1;
}

char				*flag_u(va_list *list, int *type)
{
  unsigned long long int	res;

  if (!list)
    return (NULL);
  *type = TYPE_UNSIGNED;
  res = (unsigned long long int)va_arg(list, unsigned int);
  return (my_put_llu_nbr(res));
}

char				*flag_lu(va_list *list, int *type)
{
  unsigned long long int	res;

  if (!list)
    return (NULL);
  res = (unsigned long long int)va_arg(list, unsigned long int);
  *type = TYPE_UNSIGNED;
  return (my_put_llu_nbr(res));
}

char				*flag_llu(va_list *list, int *type)
{
  unsigned long long int	res;

  if (!list)
    return (NULL);
  *type = TYPE_UNSIGNED;
  res = va_arg(list, unsigned long long int);
  return (my_put_llu_nbr(res));
}

char				*flag_hu(va_list *list, int *type)
{
  unsigned long long  int	res;

  if (!list)
    return (NULL);
  *type = TYPE_UNSIGNED;
  res = (unsigned long long int)va_arg(list, int);
  return (my_put_llu_nbr(res));
}
