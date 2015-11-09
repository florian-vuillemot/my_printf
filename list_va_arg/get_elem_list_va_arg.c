/*
** list_va_arg.c for list in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov  8 14:37:00 2015 Florian Vuillemot
** Last update Mon Nov  9 12:03:38 2015 Florian Vuillemot
*/

#include		"list_va_arg.h"

char			*get_index_arg(t_list_va_arg *arg, unsigned int index)
{
  t_node_va_arg		*node;

  if (!arg)
    return (NULL);
  node = arg->first_elem;
  while (node && node->index != index)
    node = node->next;
  if (node)
    return (node->arg);
  return (NULL);
}

char			*get_arg(t_list_va_arg *arg)
{
  char			*res;

  if (!arg)
    return (NULL);
  if (arg->cursor)
    {
      res = arg->cursor->arg;
      arg->cursor = arg->cursor->next;
      return (res);
    }
  return (NULL);
}
