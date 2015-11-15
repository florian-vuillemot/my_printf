/*
** node_va_arg.c for node in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov  8 14:22:01 2015 Florian Vuillemot
** Last update Sat Nov 14 23:06:59 2015 Florian Vuillemot
*/

#include			"node_va_arg.h"

t_node_va_arg			*init_node_va_arg(t_flag *flag,
						  unsigned int num_flag,
						  va_list *list,
						  unsigned int index)
{
  t_node_va_arg			*res;
  int				type;

  if (!flag || !list)
    return (NULL);
  type = 0;
  if ((res = malloc(sizeof(*res) * 1)) == NULL)
    return (NULL);
  if ((res->arg = flag->flag_and_fct[num_flag].flag_fct(list, &type)) == NULL)
    {
      free(res);
      return (NULL);
    }
  res->next = NULL;
  res->index = index;
  res->type = type;
  res->complete_width = ' ';
  return (res);
}

t_node_va_arg			*add_node_va_arg(t_flag *flag,
						 unsigned int num_flag,
						 t_node_va_arg *arg,
						 va_list *list)
{
  if (!flag || !list)
    return (NULL);
  if (!arg)
    return (init_node_va_arg(flag, num_flag, list, 1));
  return ((arg->next = 
	   init_node_va_arg(flag, num_flag, list, arg->index + 1)));
}

void				free_node_va_arg(t_node_va_arg *arg)
{
  t_node_va_arg			*help_free;

  while (arg)
    {
      help_free = arg;
      arg = arg->next;
      if (help_free->arg)
	free(help_free->arg);
      free(help_free);
    }
}

void				free_node(t_node_va_arg *arg)
{
  if (arg == NULL)
    return ;
  if (arg->arg)
    free(arg->arg);
  free(arg);  
}
