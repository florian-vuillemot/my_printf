/*
** node_va_arg.h for node in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov  8 14:14:09 2015 Florian Vuillemot
** Last update Tue Nov 10 00:26:07 2015 Florian Vuillemot
*/

#ifndef			NODE_VA_ARG_H_
# define		NODE_VA_ARG_H_

# include		<stdarg.h>
# include		"flag_and_function.h"

typedef struct		s_node_va_arg
{
  unsigned int		index;
  char			*arg;
  int			type;
  char			complete_width;
  struct s_node_va_arg	*next;
}			t_node_va_arg;

/* node_va_arg */
t_node_va_arg		*init_node_va_arg(t_flag *, unsigned int,
					  va_list *, unsigned int);
t_node_va_arg		*add_node_va_arg(t_flag *, unsigned int,
					 t_node_va_arg *, va_list *);
void			free_node_va_arg(t_node_va_arg *);

#endif /* !NODE_VA_ARG_H_ */
