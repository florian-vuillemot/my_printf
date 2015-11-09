/*
** flag_with_fct.c for flag in /home/vuille_f/PSU_2015_my_printf/flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 18:58:37 2015 Florian Vuillemot
** Last update Mon Nov  9 16:06:08 2015 Florian Vuillemot
*/

#include		"flag_with_fct.h"

char			*fc(va_list *d, int *type)
{
  char			*res;
  va_list		copy;

  if (!d || !*d)
    return (NULL);
  *type = CHARACTER;
  if ((res = va_arg(d, char *)) == NULL)
    return (my_strdup("(null)"));
  return (my_strdup(res));
}

t_flag_with_fct		*init_flag_with_fct()
{
  t_flag_with_fct	*res;

  if ((res = malloc(sizeof(*res) * (NB_FCT + 1))) == NULL)
    return (NULL);
  res[0].flag_fct = &fc;
  res[0].flag = my_strdup("p");
  res[1].flag_fct = &fc;
  res[1].flag = my_strdup("d");
  res[NB_FCT].flag_fct = 0;
  res[NB_FCT].flag = 0;
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
