/*
** list_va_arg.c for list in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov  8 14:37:00 2015 Florian Vuillemot
** Last update Sun Nov 15 13:27:17 2015 Florian Vuillemot
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

void pr(t_list_va_arg *res)
{
  t_list_va_arg *l;
  l = res;
  while (l->first_elem)
    {
      printf("list : %s\n",l->first_elem->arg);
      l->first_elem = l->first_elem->next;
    }
}

t_list_va_arg		*init_list_va_arg(t_flag *flag, char *str,
					  va_list *list)
{
  t_list_va_arg		*res;
  int			num_flag;
  char			*r_str;

  if ((r_str = str) == NULL || list == NULL || flag == NULL ||
      (res = init_and_check_var_list_va_arg(flag, str, list, &num_flag)) == 0)
    return (NULL);
  while (*r_str > 0)
    {
      if (*r_str == '%')
	{
	  if ((res = add_list_if_star(res, flag, ++r_str, list)) == NULL)
	    return (NULL);
	  if ((num_flag = contain_flag_fct_star(flag, r_str)) > -1)
	    if ((res = add_list_va_arg(res, flag, list,
				       (unsigned int)num_flag)) == 0)
	      return (NULL);
	}
      r_str = r_str + (*r_str ? 1 : 0);
    }
  return (res);
}

t_list_va_arg		*add_list_if_star(t_list_va_arg *arg, t_flag *flag,
					  char *str, va_list *list)
{
  unsigned int		i;
  int			nb;

  if (!arg || !str || !list || !flag || !flag->flag_and_fct)
    return (NULL);
  nb = contain_star(str);
  while (nb-- > 0)
    {
      i = 0;
      while (flag->flag_and_fct[i].flag && *flag->flag_and_fct[i].flag != 'd')
	if (flag->flag_and_fct[++i].flag == NULL)
	  return (arg);
      if (!arg->first_elem)
	{
	  if (!(arg->first_elem = add_node_va_arg(flag, i, NULL, list)))
	    return (free_list_va_arg(arg));
	  arg->cursor = arg->first_elem;
	  arg->last_elem = arg->first_elem;
	}
      else
	if (!(arg->last_elem = add_node_va_arg(flag, i, arg->last_elem, list)))
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
