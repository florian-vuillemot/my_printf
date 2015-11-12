/*
** flag_j_z.c for  in /home/vuille_f/PSU_2015_my_printf/flag_fct
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov 11 11:55:20 2015 Florian Vuillemot
** Last update Wed Nov 11 14:15:03 2015 Florian Vuillemot
*/

#include			"flag_function.h"

void				get_flag_intmax(t_flag_with_fct *tab,
						unsigned int *nb)
{
  if (!nb || !tab)
    return ;
  tab[*nb].flag_fct = &flag_jd;
  tab[*nb].flag = my_strdup("jd");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_ju;
  tab[*nb].flag = my_strdup("ju");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_td;
  tab[*nb].flag = my_strdup("td");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_tu;
  tab[*nb].flag = my_strdup("tu");
  *nb = *nb + 1;
}

char				*flag_jd(va_list *list, int *type)
{
  long long int			res;

  if (!list || !type)
    return (NULL);
  res = (long long int)va_arg(list, intmax_t);
  return (my_put_ll_nbr(res));
}

char				*flag_ju(va_list *list, int *type)
{
  unsigned long long int	res;

  if (!list || !type)
    return (NULL);
  res = (unsigned long long int)va_arg(list, uintmax_t);
  return (my_put_llu_nbr(res));
}

char				*flag_td(va_list *list, int *type)
{
  long long int			res;

  if (!list || !type)
    return (NULL);
  res = (long long int)va_arg(list, ptrdiff_t);
  return (my_put_ll_nbr(res));
}

char				*flag_tu(va_list *list, int *type)
{
  unsigned long long int	res;

  if (!list || !type)
    return (NULL);
  res = (unsigned long long int)va_arg(list, ptrdiff_t);
  return (my_put_llu_nbr(res));
}
