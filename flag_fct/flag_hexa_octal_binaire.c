/*
** flag_hexa_octal_binaire.c for convert in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov 11 09:51:03 2015 Florian Vuillemot
** Last update Sun Nov 15 11:35:38 2015 Florian Vuillemot
*/

#include			"flag_function.h"

void				get_flag_h_o_b(t_flag_with_fct *tab,
					       unsigned int *nb)
{
  if (!tab || !nb)
    return ;
  tab[*nb].flag_fct = &flag_x;
  tab[*nb].flag = my_strdup("x");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_x_maj;
  tab[*nb].flag = my_strdup("X");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_o;
  tab[*nb].flag = my_strdup("o");
  *nb = *nb + 1;
  tab[*nb].flag_fct = &flag_b;
  tab[*nb].flag = my_strdup("b");
  *nb = *nb + 1;
}

char				*flag_x(va_list *list, int *type)
{
  unsigned long int		hexa;

  if (!list || !type)
    return (NULL);
  hexa = (unsigned long int)va_arg(list, unsigned int);
  if (hexa == 0)
    *type = NO_TYPE;
  else
    *type = CONVERT_MIN;
  return (convert_hexa(hexa, "0123456789abcdef"));
}

char				*flag_x_maj(va_list *list, int *type)
{
  unsigned long int		hexa;

  if (!list || !type)
    return (NULL);
  hexa = (unsigned long int)va_arg(list, unsigned int);
  if (hexa == 0)
    *type = NO_TYPE;
  else
    *type = CONVERT_MAJ;
  return (convert_hexa(hexa, "0123456789ABCDEF"));
}

char				*flag_o(va_list *list, int *type)
{
  unsigned long int		oct;

  if (!list || !type)
    return (NULL);
  oct = (unsigned long int)va_arg(list, unsigned int);
  if (oct == 0)
    *type = NO_TYPE;
  else
    *type = OCTAL;
  return (convert_octal(oct));
}

char				*flag_b(va_list *list, int *type)
{
  unsigned long int		res;

  if (!list || !type)
    return (NULL);
  res = (unsigned long int)va_arg(list, unsigned int);
  *type = NO_TYPE;
  return (convert_binaire(res));
}
