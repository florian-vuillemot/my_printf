/*
** flag_function.h for  in /home/vuille_f/PSU_2015_my_printf/fct_flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Tue Nov 10 16:56:31 2015 Florian Vuillemot
** Last update Mon Nov 16 11:00:14 2015 Florian Vuillemot
*/

#ifndef			FLAG_FUNCTION_H_
# define		FLAG_FUNCTION_H_

# include		<stdio.h>
# include		<stdarg.h>
# include		<inttypes.h>
# include		<stddef.h>
# include		"flag_with_fct.h"
# include		"my_string.h"
# include		"struct_string.h"

/* flag_integer_long_short nb_fct += 8 */
void			get_flag_integer_long_short(t_flag_with_fct *,
						      unsigned int *);
char			*flag_d(va_list *, int *);
char			*flag_ld(va_list *, int *);
char			*flag_lld(va_list *, int *);

/* flag_unsigned_long_short nb fct += 4 */
void			get_flag_unsigned_long_short(t_flag_with_fct *,
						     unsigned int *);
char			*flag_u(va_list *, int *);
char			*flag_lu(va_list *, int *);
char			*flag_llu(va_list *, int *);
char			*flag_hu(va_list *, int *);

/* flag_p nb_fct += 1 */
void			get_flag_p(t_flag_with_fct *, unsigned int *);
char			*flag_p(va_list *, int *);

/* flag_string nb_fct += 5 (s maj) */
void			get_flag_string(t_flag_with_fct *, unsigned int *);
char			*flag_s(va_list *, int *);
char			*flag_c(va_list *, int *);


/* flag_hexa_octal_binaire nb_fct += 4 */
void			get_flag_h_o_b(t_flag_with_fct *, unsigned int *);
char			*flag_x(va_list *, int *);
char			*flag_x_maj(va_list *, int *);
char			*flag_o(va_list *, int *);
char			*flag_b(va_list *, int *);

/* flag_hexa_octal_binaire_unsigned_long nb_fct += 4 */
void			get_flag_h_o_b_long(t_flag_with_fct *, unsigned int *);
char			*flag_x_long(va_list *, int *);
char			*flag_x_maj_long(va_list *, int *);
char			*flag_o_long(va_list *, int *);
char			*flag_b_long(va_list *, int *);

/* flag_j_z nb_fct += 4 */
void			get_flag_intmax(t_flag_with_fct *, unsigned int *);
char			*flag_jd(va_list *, int *);
char			*flag_ju(va_list *, int *);
char			*flag_td(va_list *, int *);
char			*flag_tu(va_list *, int *);

/* flag_modulo nb_fct += 1 */
void			get_flag_m(t_flag_with_fct *, unsigned int *);
char			*flag_modulo(va_list *, int *);

/* convert_hexa */
char            *convert_hexa(unsigned long int, char *);

/* convert_octal */
char            *convert_octal(unsigned long int);

/* convert_char_octal nb_fct */
char			*flag_s_maj(va_list *, int *);

/* convert_binary */
char            *convert_binary(unsigned long int);
#endif
