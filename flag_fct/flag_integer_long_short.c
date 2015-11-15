/*
** flag_d.c for flag_d in /home/vuille_f/PSU_2015_my_printf/fct_flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 15:36:19 2015 Florian Vuillemot
** Last update Sun Nov 15 19:01:19 2015 Florian Vuillemot
*/

#include		"flag_function.h"

static void		ini_integer_l_s(t_flag_with_fct *tab,
					unsigned int *nb)
{
  if (!tab || !nb)
    return ;
  tab[*nb].flag_fct = &flag_d;
  tab[*nb].flag = my_strdup("hi");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_ld;
  tab[*nb].flag = my_strdup("li");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_lld;
  tab[*nb].flag = my_strdup("lli");
  *nb = *nb + 1;
}

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
  ini_integer_l_s(tab, nb);
}

char			*flag_d(va_list *list, int *type)
{
  long int		res;

  if (!list)
    return (NULL);
  res = (long int)va_arg(*list, int);
  if (res < 0)
    {
      *type = INTEGER_MINUS;
      res = res * -1;
    }
  else
    *type = INTEGER_POS;
  return (my_putnbr_string(res));
}

char			*flag_ld(va_list *list, int *type)
{
  long int		res;
  char			*nb_char;
  char			*help_free;

  if (!list)
    return (NULL);
  res = va_arg(*list, long int);
  if (res < 0)
    {
      *type = INTEGER_MINUS;
      if ((help_free = my_putnbr_string(res)) == NULL)
	return (NULL);
      nb_char = my_strdup(help_free + 1);
      free(help_free);
      return (nb_char);
    }
  else
    *type = INTEGER_POS;
  return (my_putnbr_string(res));
}

char			*flag_lld(va_list *list, int *type)
{
  long long int		res;
  char			*nb_char;
  char			*help_free;

  if (!list)
    return (NULL);
  res = va_arg(*list, long long int);
  if (res < 0)
    {
      *type = INTEGER_MINUS;
      if ((help_free = my_putnbr_string(res)) == NULL)
	return (NULL);
      nb_char = my_strdup(help_free + 1);
      free(help_free);
      return (nb_char);
    }
  else
    *type = INTEGER_POS;
  return (my_put_ll_nbr(res));
}
