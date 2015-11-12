/*
** list_va_arg.c for list in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov  8 14:37:00 2015 Florian Vuillemot
** Last update Thu Nov 12 07:02:48 2015 Florian Vuillemot
*/

#include		"list_va_arg.h"

static t_list_va_arg	*init_and_check_var_list_va_arg(t_flag *flag,
							char *str,
							va_list *list,
							int *num_flag)
{
  t_list_va_arg		*res;

  if (!flag || !str || !list)
    return (NULL);
  if ((res = malloc(sizeof(*res) * 1)) == NULL)
    return (NULL);
  res->cursor = NULL;
  res->first_elem = NULL;
  res->last_elem = NULL;
  *num_flag = 0;
  return (res);
}

t_list_va_arg		*init_list_va_arg(t_flag *flag, char *str,
					  va_list *list)
{
  t_list_va_arg		*res;
  int			num_flag;
  char			*r_str;

  if ((res = init_and_check_var_list_va_arg(flag, str, list, &num_flag)) == 0)
    return (NULL);
  r_str = str - 1;
  while (*(r_str = r_str + 1))
    if (*r_str == '%')
      {
	if ((res = add_list_if_start(res, flag, r_str + 1, list)) == NULL)
	  return (NULL);
	if ((num_flag = contain_flag_fct(flag, r_str + 1)) > -1)
	  if ((res =
	       add_list_va_arg(res, flag, list, (unsigned int)num_flag))
	      == NULL)
	    return (NULL);
      }
  if ((res = check_dollar_in_string(res, flag, str, list)) == NULL)
    return (NULL);
  return (res);
}


/*
**
**
**
** ATTENTION
**
**
 */
t_list_va_arg		*check_dollar_in_string(t_list_va_arg *arg,
						t_flag *flag, char *str,
						va_list *list)
{
  unsigned int		max;
  int			i;

  if (!arg || !arg->last_elem || !flag || !str || !list)
    return (NULL);
  max = 0;
  while (*str)
    {
      if (*str == '%' && contain_flag_fct(flag, str + 1) > -1)
	{
	  i = 1;
	  while (str[i] <= '9' && str[i] >= '0')
	    i = i + 1;
	  if (str[i] == '$')
	    max = (unsigned int)MAX(my_getnbr(str + 1), (int)max);
	}
      str = str + 1;
    }
  while (max > arg->last_elem->index)
    if (!(arg->last_elem = add_node_va_arg(flag, NUM_FLAG_STAR,
					   arg->last_elem, list)))
      return (free_list_va_arg(arg));
  return (arg);
}

t_list_va_arg		*add_list_if_start(t_list_va_arg *arg, t_flag *flag,
					   char *str, va_list *list)
{
  if (!arg || !str || !list)
    return (NULL);
  if (contain_star(str))
    {
      if (!arg->first_elem)
	{
	  if (!(arg->first_elem = add_node_va_arg(flag, NUM_FLAG_STAR,
						  NULL, list)))
	    return (free_list_va_arg(arg));
	  arg->cursor = arg->first_elem;
	  arg->last_elem = arg->first_elem;
	  return (arg);
	}
      if (!(arg->last_elem = add_node_va_arg(flag, NUM_FLAG_STAR,
					     arg->last_elem, list)))
	return (free_list_va_arg(arg));
    }
  return (arg);
}

t_list_va_arg		*add_list_va_arg(t_list_va_arg *arg, t_flag *flag,
					va_list *list, unsigned int num_flag)
{
  if (!arg || !flag || !list)
    return (NULL);
  if (!arg->first_elem)
    {
      if (!(arg->first_elem = add_node_va_arg(flag, num_flag, NULL, list)))
	return (free_list_va_arg(arg));
      arg->cursor = arg->first_elem;
      arg->last_elem = arg->first_elem;
      return (arg);
    }
  if (!(arg->last_elem = add_node_va_arg(flag, num_flag,
					 arg->last_elem, list)))
      return (free_list_va_arg(arg));
  return (arg);
}

t_list_va_arg		*free_list_va_arg(t_list_va_arg *arg)
{
  if (arg)
    {
      if (arg->first_elem)
	free_node_va_arg(arg->first_elem);
      free(arg);
    }
  return (NULL);
}
