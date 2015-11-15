/*
** replace_star_and_dollar.c for  in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov 14 13:07:45 2015 Florian Vuillemot
** Last update Sun Nov 15 10:04:11 2015 Florian Vuillemot
*/

#include		"list_va_arg.h"

/* static t_string		*check_dollar(t_string *string, va_list *list, */
/* 				      unsigned int cur) */
/* { */
/*   int			nb; */
/*   char			*str; */
/*   int			i; */

/*   if (!string || !list) */
/*     return (NULL); */
/*   if ((nb = my_getnbr(string->string + i)) < 0) */
/*     return (string); */
/*   i = -1; */
/*   while (++i < nb) */
/*     va_arg(list, int); */

/*   if ((string = insert_string(string, str, cur)) == NULL) */
/*     return (NULL); */
/*   cur += my_strlen(str); */
/*   while (string && ((string->string[cur] <= '9' && string->string[cur] >= '0') */
/* 		    || string->string[cur] == '$')) */
/*     string = remove_elem_to_string(string, cur); */
/*   if (string && (found_char_in_string(string->string[cur], TYPE_L_S_P) || */
/* 		 found_char_in_string(string->string[cur], TYPE_INTEGER))) */
/*     { */
/*       while (string && found_char_in_string(string->string[cur], TYPE_L_S_P)) */
/* 	string = remove_elem_to_string(string, cur); */
/*       while (string && found_char_in_string(string->string[cur], TYPE_INTEGER)) */
/* 	string = remove_elem_to_string(string, cur); */
/*     } */
/*   else */
/*     while (string && found_char_in_string(string->string[cur], "sSc")) */
/*       string = remove_elem_to_string(string, cur); */
/*   return (string); */
/* } */

t_string		*get_star(t_string *string, unsigned int cur,
				  unsigned int nb_pop, va_list *list)
{
  unsigned int		pop;
  va_list		copy_list;
  char			*res;

  if (!list || !string || !string->string)
    return (NULL);
  pop = 1;
  va_copy(copy_list, *list);
  while (pop++ < nb_pop)
    va_arg(copy_list, int);
  string = remove_elem_to_string(string, cur);
  if ((res = my_putnbr_string((long int)va_arg(copy_list, int))) == NULL)
    return (free_string(string));
  string = insert_string(string, res, cur);
  free(res);
  return (string);
}

t_string		*replace_star_and_dollar(t_string *string,
						 t_list_va_arg *stack,
						 t_flag *flag, va_list *list)
{
  unsigned int		i;
  unsigned int		j;
  unsigned int		nb_pop;
  unsigned int		to_delete;

  if (!string || !list || !string->string)
    return (NULL);
  i = 0;
  nb_pop = 1;
  to_delete = 0;
  while (string && string->string[i])
    {
      if (string->string[i] == '%')
	{
	  j = 1;
	  while (string->string[i + j] <= '9' && string->string[i + j] >= '0')
	    j++;
	  /* if (j > 1 && string->string[i + j] == '$') */
	  /*   { */
	  /*     string = remove_elem_to_string(string, i); */
	  /*     string = check_dollar(string, list, i); */
	  /*   } */
	  if (string && string->string[i + j] == '*')
	    {
	      string = get_star(string, i + j, nb_pop, list);
	      stack = delete_arg(stack, nb_pop++);
	    }
	  while (string->string[i + j] <= '9' && string->string[i + j] >= '0')
	    j++;
	  if (string && string->string[i + j] == '.')
	    j++;
	  if (string && string->string[i + j] == '*')
	    {
	      string = get_star(string, i + j, nb_pop, list);
	      stack = delete_arg(stack, nb_pop++);
	    }
	  if (string->string[i + j] &&
	      contain_flag_fct_star(flag, string->string + i + j) > -1)
	    nb_pop++;
	}
      i++;
    }
  return (string);
}
