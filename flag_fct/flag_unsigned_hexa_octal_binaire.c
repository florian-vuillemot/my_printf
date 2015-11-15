/*
** flag_hexa_octal_binaire.c for convert in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov 11 09:51:03 2015 Florian Vuillemot
** Last update Sat Nov 14 21:08:28 2015 Florian Vuillemot
*/

#include			"flag_function.h"

void				get_flag_h_o_b_long(t_flag_with_fct *tab,
						    unsigned int *nb)
{
  if (!tab || !nb)
    return ;
  tab[*nb].flag_fct = &flag_x_long;
  tab[*nb].flag = my_strdup("lx");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_x_maj_long;
  tab[*nb].flag = my_strdup("lX");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_o_long;
  tab[*nb].flag = my_strdup("lo");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_b_long;
  tab[*nb].flag = my_strdup("lb");
  *nb = *nb + 1;
}

char				*flag_x_long(va_list *list, int *type)
{
  unsigned long int		hexa;

  if (!list || !type)
    return (NULL);
  hexa = va_arg(list, unsigned long int);
  if (hexa == 0)
    *type = NO_TYPE;
  else
    *type = CONVERT_MIN;
  return (convert_hexa(hexa, "0123456789abcdef"));
}

char				*flag_x_maj_long(va_list *list, int *type)
{
  unsigned long int		hexa;

  if (!list || !type)
    return (NULL);
  hexa = va_arg(list, unsigned long int);
  if (hexa == 0)
    *type = NO_TYPE;
  else
    *type = CONVERT_MAJ;
  return (convert_hexa(hexa, "0123456789ABCDEF"));
}

char				*flag_o_long(va_list *list, int *type)
{
  unsigned long int		oct;

  if (!list || !type)
    return (NULL);
  oct = va_arg(list, unsigned long int);
  if (oct == 0)
    *type = NO_TYPE;
  else
    *type = OCTAL;
  return (convert_octal(oct));
}

char				*flag_b_long(va_list *list, int *type)
{
  unsigned long int		res;

  if (!list || !type)
    return (NULL);
  res = va_arg(list, unsigned long int);
  *type = NO_TYPE;
  return (convert_binaire(res));
}
