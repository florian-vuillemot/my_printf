/*
** list_va_arg.c for list in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov  8 14:37:00 2015 Florian Vuillemot
** Last update Sun Nov 15 10:05:20 2015 Florian Vuillemot
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

t_list_va_arg		*delete_arg(t_list_va_arg *arg, unsigned int index)
{
  t_node_va_arg		*node;
  t_node_va_arg		*prec;

  if (!arg || !(node = arg->first_elem))
    return (arg);
  prec = NULL;
  while (node && node->index != index)
    {
      prec = node;
      node = node->next;
    }
  if (node == NULL)
    return (arg);
  if (arg->cursor == node)
    arg->cursor = node->next;
  if (prec == NULL)
    arg->first_elem = node->next;
  else
    prec->next = node->next;
  if (arg->last_elem == node)
    arg->last_elem = prec;
  free_node(node);
  return (arg);
}
