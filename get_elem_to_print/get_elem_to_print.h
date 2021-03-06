/*
** get_elem_to_print.h for get in /home/vuille_f/PSU_2015_my_printf/
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  9 10:30:16 2015 Florian Vuillemot
** Last update Sat Nov 14 10:15:13 2015 Florian Vuillemot
*/

#ifndef			GET_ELEM_TO_PRINT_H_
# define		GET_ELEM_TO_PRINT_H_

# include		"struct_string.h"
# include		"list_va_arg.h"

typedef struct		s_width_prec
{
  unsigned int		width;
  unsigned int		precision;
}			t_width_prec;

/* get_elem_to_print */
t_string		*get_elem_to_print(t_string *, t_flag *,
					   t_list_va_arg *);

/* get_attribut */
t_string		*get_flag_character(t_string *, unsigned int,
					    t_list_va_arg *, t_flag *);
t_string		*clean_string_and_get_data(t_string *,
						   unsigned int *,
						   unsigned int *,
						   t_node_va_arg *);
t_string		*clean_string_data_string(t_string *,
						  unsigned int *,
						  unsigned int *,
						  t_node_va_arg *);
t_string		*clean_string_data_convert(t_string *,
						   unsigned int *,
						   unsigned int *,
						   t_node_va_arg *);

/* get_flag_integer */
t_string		*get_flag_long(t_string *, unsigned int *,
					  t_list_va_arg *);
t_string		*get_flag_integer(t_string *, unsigned int *,
					  t_list_va_arg *);
t_string		*add_complete_width(t_string *, unsigned int *,
					    t_width_prec *, t_node_va_arg *);

/* get_flag_integer_convert */
t_string		*get_flag_integer_and_convert(t_string *,
						      unsigned int *,
						      t_list_va_arg *);

/* get_width_precision */
t_string		*get_width_precision_string_minus(t_string *,
							  t_width_prec *,
							  unsigned int,
							  t_node_va_arg *);
t_string		*get_width_precision_string(t_string *,
						    t_width_prec *,
						    unsigned int,
						    t_node_va_arg *);

/* get_width_precision_convert */
t_string		*get_width_prec_convert_minus(t_string *,
						      t_width_prec *,
						      unsigned int,
						      t_node_va_arg *);
t_string		*get_width_prec_str_convert(t_string *,
						    t_width_prec *,
						    unsigned int,
						    t_node_va_arg *);

/* get_field_width */
unsigned int		get_field_width(t_string *, unsigned int);
unsigned int		get_precision(t_string *, unsigned int,
				      t_node_va_arg *);
unsigned int		get_string_precision(t_string *, unsigned int);

/* get_flag_string */
t_string		*get_with_flag_string(t_string *, unsigned int *,
					      t_list_va_arg *);

/* get_width_precision_string */
t_string		*get_width_prec_string(t_string *,
					       t_width_prec *,
					       unsigned int,
					       t_node_va_arg *);
t_string		*get_width_prec_string_minus(t_string *,
						     t_width_prec *,
						     unsigned int,
						     t_node_va_arg *);

/* get_flag_pnt */
t_string		*get_flag_pnt(t_string *, unsigned int *,
				      t_list_va_arg *);

/* get_width_precision_pnt */
t_string		*get_width_prec_pnt_convert(t_string *,
						    t_width_prec *,
						    unsigned int,
						    t_node_va_arg *);
t_string		*get_width_prec_pnt_convert_minus(t_string *,
							  t_width_prec *,
							  unsigned int,
							  t_node_va_arg *);

/* get_flag_modulo */
t_string		*get_flag_modulo(t_string *, unsigned int *,
					 t_list_va_arg *);

#endif /* !GET_ELEM_TO_PRINT_H_ */
