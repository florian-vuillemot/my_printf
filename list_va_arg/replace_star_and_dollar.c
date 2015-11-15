/*
** replace_star_and_dollar.c for  in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov 14 13:07:45 2015 Florian Vuillemot
** Last update Sun Nov 15 15:13:06 2015 Florian Vuillemot
*/

#include		"list_va_arg.h"

static t_string		*get_star(t_string *string, unsigned int cur,
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
    return (string);
  string = insert_string(string, res, cur);
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

static unsigned int	clean_digit_and_dot(t_string *string, unsigned int cur)
{
  if (!string || !string->string)
    return (0);
  while (string->string[cur] <= '9' && string->string[cur] >= '0')
    cur++;
  if (string && string->string[cur] == '.')
    cur++;
  return (cur);
}

static int		star(t_string **string, unsigned int cursor,
			      unsigned int nb_pop, va_list *list)
{
  if (string && *string && (*string)->string &&
      (*string)->string[cursor] == '*')
    {
      *string = get_star(*string, cursor, nb_pop, list);
      return (1);
    }
  return (0);
}

t_string		*replace_star(t_string *string,
				      t_list_va_arg *stack,
				      t_flag *flag, va_list *list)
{
  unsigned int		cur;
  unsigned int		nb_pop;

  if (!string || !list || !string->string || stack || !flag)
    return (string);
  cur = 0;
  nb_pop = 1;
  while (string && string->string && string->string[cur])
    if (string->string[cur] == '%')
      {
	cur = clean_beg_string(string, cur);
	if (string && star(&string, cur, nb_pop, list))
	  stack = delete_arg(stack, nb_pop++);
	cur = clean_digit_and_dot(string, cur);
	if (string && star(&string, cur, nb_pop, list))
	  stack = delete_arg(stack, nb_pop++);
	while (string && string->string &&
	       string->string[cur] <= '9' && string->string[cur] >= '0')
	  cur++;
	if (string && string->string[cur] &&
	    contain_flag_fct_star(flag, string->string + cur) > -1)
	  nb_pop++;
      }
    else
      cur++;
  return (string);
}
