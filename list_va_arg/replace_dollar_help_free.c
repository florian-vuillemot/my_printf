/*
** replace_dollar_help_free.c for  in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov 16 10:15:20 2015 Florian Vuillemot
** Last update Mon Nov 16 10:53:56 2015 Florian Vuillemot
*/

#include	"list_va_arg.h"

char		*replace_dollar_help_free(t_string *string,
					  unsigned int cur,
					  unsigned int i,
					  char *ins)
{
  if (!string || !string->string || !ins)
    return (NULL);
  string = remove_elem_to_string(string, cur);
  string = remove_elem_to_string(string, i);
  string = insert_string(string, ins, i);
  free(ins);
  return (NULL);
}

int		get_nb_to_string(char *string)
{
  char		*copy;
  int		nb;

  if (!string)
    return (0);
  if ((copy = my_strdup(string)) == NULL)
    return (0);
  nb = my_getnbr(copy);
  free(copy);
  return (nb);
}
