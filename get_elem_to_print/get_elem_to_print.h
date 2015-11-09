/*
** get_elem_to_print.h for get in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 10:30:16 2015 Florian Vuillemot
** Last update Mon Nov  9 16:36:07 2015 Florian Vuillemot
*/

#ifndef			GET_ELEM_TO_PRINT_H_
# define		GET_ELEM_TO_PRINT_H_

# include		"struct_string.h"
# include		"list_va_arg.h"

/* get_elem_to_print */
t_string		*get_elem_to_print(t_string *, t_flag *,
					     t_list_va_arg *);

/* get_attribut */
t_string		*get_flag_character(t_string *, unsigned int,
					    t_list_va_arg *, t_flag *);
t_string		*get_flag_integer(t_string *, unsigned int,
					  int, t_list_va_arg *);
t_string		*get_width_precision_string_minus(t_string *,
							  unsigned int,
							  unsigned int,
							  t_node_va_arg *);
t_string		*get_width_precision_string(t_string *,
							  unsigned int,
							  unsigned int,
							  t_node_va_arg *);

/* get_field_width */
unsigned int		get_field_width(t_string *, unsigned int);
unsigned int		get_precision(t_string *, unsigned int,
				       t_node_va_arg *);

#endif /* !GET_ELEM_TO_PRINT_H_ */
