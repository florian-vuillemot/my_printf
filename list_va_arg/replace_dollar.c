/*
** replace_star_and_dollar.c for  in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov 14 13:07:45 2015 Florian Vuillemot
** Last update Mon Nov 16 14:51:05 2015 Florian Vuillemot
*/

#include		"list_va_arg.h"

static t_string		*replace_star_dollar(t_string *string,
					     unsigned int cur,
					     t_len_dollar *data,
					     va_list *list)
{
  unsigned int		pop;
  va_list		copy_list;
  int			nb_space;

  if (!list || !string || !string->string || !data)
    return (NULL);
  pop = 1;
  va_copy(copy_list, *list);
  while (pop++ < data->pop)
    va_arg(copy_list, int);
  while (cur > 0 && string->string[cur] != '*')
    cur--;
  string = remove_elem_to_string(string, cur);
  nb_space = va_arg(copy_list, int) - data->width;
  while (nb_space-- > 0)
    string = add_elem_to_string(string, cur, ' ');
  data->pop = 0;
  return (string);
}

char			*get_insert_dollar(char *str, t_flag *flag,
					   unsigned int nb_pop,
					   va_list *list)
{
  int			nb_flag;
  va_list		copy;

  if (!str || !flag || !list)
    return (NULL);
  va_copy(copy, *list);
  if ((nb_flag = cmp_string_and_flag(flag, str)) < 0)
    return (NULL);
  while (nb_pop-- > 1)
    va_arg(copy, int);
  return (flag->flag_and_fct[nb_flag].flag_fct(&copy, &nb_flag));
}

static unsigned int	star_and_dollar(t_string **string, unsigned int cur,
					t_flag *flag, unsigned int *star)
{
  unsigned int		last;
  unsigned int		nb;

  if (!string || !(*string) || !(*string)->string || !flag || !star)
    return (0);
  if ((*string)->string[cur++] != '*')
    return (0);
  last = cur;
  if ((nb = get_nb_to_string((*string)->string + cur)) < 1)
    return (0);
  while ((*string)->string[cur] >= '0' && (*string)->string[cur] <= '9')
    cur++;
  if (last == cur || (*string)->string[cur] != '$')
    return (0);
  while (string && *string && (*string)->string &&
	 (((*string)->string[last] <= '9' && (*string)->string[last] >= '0') ||
	  ((*string)->string[last] == '$')))
    *string = remove_elem_to_string(*string, last);
  *star = nb;
  return (nb);
}

static unsigned int	there_are_dollar(t_string **string, unsigned int cur,
					 t_flag *flag, unsigned int *star)
{
  int			nb;
  unsigned int		i;

  if (!string || !(*string) || !(*string)->string || !flag)
    return (0);
  i = cur;
  if ((nb = get_nb_to_string((*string)->string + cur)) < 1)
    return (0);
  while ((*string)->string[i] <= '9' && (*string)->string[i] >= '0')
    i++;
  if ((*string)->string[i] != '$' || cur == i)
    return (0);
  if ((*string)->string[++i] == '*')
    star_and_dollar(string, i++, flag, star);
  if ((*string)->string[i] &&
      cmp_string_and_flag(flag, (*string)->string + i) > -1)
    while (string && *string && (*string)->string &&
	   (((*string)->string[cur] <= '9' && (*string)->string[cur] >= '0')
	    || (*string)->string[cur] == '$'))
      *string = remove_elem_to_string(*string, cur);
  else
    nb = 0;
  return (nb);
}

t_string		*replace_dollar(t_string *string,
					t_list_va_arg *arg,
					t_flag *flag, va_list *list)
{
  unsigned int		cur;
  unsigned int		i;
  unsigned int		nb_pop;
  t_len_dollar		data;
  char			*ins;

  if (!string || !list || !string->string || !arg || !flag || !arg->first_elem)
    return (string);
  cur = 0;
  data.pop = 0;
  while (string && string->string && string->string[cur])
    if (string->string[cur++] == '%' && string->string[cur] &&
  	(nb_pop = there_are_dollar(&string, cur, flag, &data.pop)) > 0)
      {
  	i = cur;
  	while (data.pop && string->string[i] && string->string[i - 1] != '*')
  	  i++;
  	ins = get_insert_dollar(string->string + i, flag, nb_pop, list);
	data.width = my_strlen(ins);
  	ins = replace_dollar_help_free(string, cur - 1, --i, ins);
  	if (data.pop)
  	  string = replace_star_dollar(string, cur, &data, list);
      }
  return (string);
}
