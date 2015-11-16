/*
** replace_star_and_dollar.c for  in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov 14 13:07:45 2015 Florian Vuillemot
** Last update Mon Nov 16 16:01:31 2015 Florian Vuillemot
*/

#include		"list_va_arg.h"

static t_string		*get_star(t_string *string, unsigned int cur,
				  unsigned int nb_pop, va_list *list)
{
  unsigned int		pop;
  va_list		copy_list;
  char			*res;
  long int		sign;

  if (!list || !string || !string->string)
    return (NULL);
  pop = 1;
  va_copy(copy_list, *list);
  while (pop++ < nb_pop)
    va_arg(copy_list, int);
  string = remove_elem_to_string(string, cur);
  sign = (long int)va_arg(copy_list, int);
  if ((res = my_putnbr_string(sign)) == NULL)
    return (string);
  string = insert_string(string, res, cur);
  pop = (sign < 0 ? 0 : 5);
  while (cur > 0 && pop < 2 && string->string[cur] != '%')
    if (string->string[cur--] == '-')
      pop++;
  if (pop == 2 && string->string[cur + 1] == '-')
    string = remove_elem_to_string(string, cur + 1);
  free(res);
  return (string);
}

static unsigned int	clean_beg_string(t_string *string, unsigned int cur)
{
  if (!string || !string->string)
    return (0);
  cur++;
  while (string->string[cur] &&
	 found_char_in_string(string->string[cur], PRIOR_CHARACTER))
    cur++;
  while (string->string[cur] <= '9' && string->string[cur] >= '0')
    cur++;
  return (cur);
}

static unsigned int	clean_digit_and_dot(t_string *string, unsigned int cur,
					    int dot_include)
{
  if (!string || !string->string)
    return (0);
  while (string->string[cur] <= '9' && string->string[cur] >= '0')
    cur++;
  if (dot_include)
    {
      if (string && string->string[cur] == '.')
	cur++;
      else
	while (string && string->string[cur] == '*')
	  cur++;
    }
  return (cur);
}

static int		star(t_string **string, unsigned int cursor,
			      unsigned int nb_pop, va_list *list)
{
  if (string && *string && (*string)->string && cursor > 0 &&
      ((((*string)->string[cursor - 1] < '0' ||
	 (*string)->string[cursor - 1] > '9') &&
	(*string)->string[cursor] == '*') ||
       (cursor > 1 && (*string)->string[cursor - 1] == '0' &&
	((*string)->string[cursor - 2] < '0' ||
	 (*string)->string[cursor - 2] > '9'))))
    {
      *string = get_star(*string, cursor, nb_pop, list);
      return (1);
    }
  return (0);
}

t_string		*replace_star(t_string *string,
				      t_list_va_arg *arg,
				      t_flag *flag, va_list *list)
{
  unsigned int		cur;
  unsigned int		nb_pop;

  if (!string || !list || !string->string || !arg || !flag || !arg->first_elem)
    return (string);
  cur = 0;
  nb_pop = 1;
  while (string && string->string && string->string[cur])
    if (string->string[cur] == '%')
      {
	cur = clean_beg_string(string, cur);
	if (string && star(&string, cur, nb_pop, list))
	  arg = delete_arg(arg, nb_pop++);
	cur = clean_digit_and_dot(string, cur, 1);
	if (string && star(&string, cur, nb_pop, list))
	  arg = delete_arg(arg, nb_pop++);
	cur = clean_digit_and_dot(string, cur, 0);
	if (string && string->string[cur] &&
	    contain_flag_fct_star(flag, string->string + cur) > -1)
	  nb_pop++;
      }
    else
      cur++;
  return (string);
}
