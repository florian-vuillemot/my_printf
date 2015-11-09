/*
** list_va_arg.h for list in /home/vuille_f/PSU_2015_my_printf/list_va_arg
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov  8 14:10:21 2015 Florian Vuillemot
** Last update Sun Nov  8 17:41:42 2015 Florian Vuillemot
*/

#ifndef			LIST_VA_ARG_H_
# define		LIST_VA_ARG_H_

# include		"node_va_arg.h"

typedef struct		s_list_va_arg
{
  t_node_va_arg		*cursor;
  t_node_va_arg		*first_elem;
  t_node_va_arg		*last_elem;
}			t_list_va_arg;

/* récupére le char* est tout les *, $ qu'il y a dedans */
t_list_va_arg		*init_list_va_arg(t_flag *, char *, va_list *);
t_list_va_arg		*check_dollar_in_string(t_list_va_arg *, t_flag *,
						char *, va_list *);
t_list_va_arg		*add_list_if_start(t_list_va_arg *, t_flag *,
					   char *, va_list *);
t_list_va_arg		*add_list_va_arg(t_list_va_arg *, t_flag *,
					 va_list *, unsigned int);
t_list_va_arg		*free_list_va_arg(t_list_va_arg *);

/* get_elem_list_va_arg */
char			*get_index_arg(t_list_va_arg *, unsigned int);
char			*get_arg(t_list_va_arg *);

#endif /* !LIST_VA_ARG_H_ */
