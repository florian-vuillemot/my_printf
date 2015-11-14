/*
** flag_with_fct.c for flag in /home/vuille_f/PSU_2015_my_printf/flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 18:58:37 2015 Florian Vuillemot
** Last update Sat Nov 14 10:14:09 2015 Florian Vuillemot
*/

#include		"flag_with_fct.h"

t_flag_with_fct		*init_flag_with_fct()
{
  t_flag_with_fct	*res;
  unsigned int		nb;

  if ((res = malloc(sizeof(*res) * (NB_FCT + 1))) == NULL)
    return (NULL);
  nb = 0;
  get_flag_integer_long_short(res, &nb);
  get_flag_unsigned_long_short(res, &nb);
  get_flag_unsigned_long_short(res, &nb);
  get_flag_p(res, &nb);
  get_flag_string(res, &nb);
  get_flag_intmax(res, &nb);
  get_flag_h_o_b(res, &nb);
  get_flag_m(res, &nb);
  res[nb].flag_fct = 0;
  res[nb].flag = 0;
  return (res);
}

void			free_flag_with_fct(t_flag_with_fct *flag_and_fct)
{
  t_flag_with_fct	*first_elem;
  int			i;

  if ((first_elem = flag_and_fct))
    {
      i = 0;
      while (flag_and_fct[i].flag_fct)
	{
	  if (flag_and_fct[i].flag)
	    free(flag_and_fct[i].flag);
	  i = i + 1;
	}
      free(first_elem);
    }
}
