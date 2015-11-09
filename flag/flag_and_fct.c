/*
** flag_and_fct.c for flag_and_fct in /home/vuille_f/PSU_2015_my_printf/flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 18:50:10 2015 Florian Vuillemot
** Last update Sun Nov  8 17:52:03 2015 Florian Vuillemot
*/

#include		"flag_and_function.h"

t_flag			*init_flag_and_fct()
{
  t_flag		*res;

  if ((res = malloc(sizeof(*res) * 1)) == NULL)
    return (NULL);
  if ((res->flag_and_fct = init_flag_with_fct()) == NULL)
    {
      free(res);
      return (NULL);
    }
  if ((res->autorized_with_flag = my_strdup(" +-0#")) == NULL)
    {
      free_flag_with_fct(res->flag_and_fct);
      free(res);
      return (NULL);
    }
  return (res);
}

void			free_flag_and_fct(t_flag *flag)
{
  if (flag)
    {
      if (flag->flag_and_fct)
	free_flag_with_fct(flag->flag_and_fct);
      if (flag->autorized_with_flag)
	free(flag->autorized_with_flag);
      free(flag);
    }
}
