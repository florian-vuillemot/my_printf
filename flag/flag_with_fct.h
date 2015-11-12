/*
** flag_with_fct.h for fct in /home/vuille_f/PSU_2015_my_printf/flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 18:55:41 2015 Florian Vuillemot
** Last update Thu Nov 12 01:56:10 2015 Florian Vuillemot
*/

#ifndef			FLAG_WITH_FCT_H_
# define		FLAG_WITH_FCT_H_

# include		<stdarg.h>
# include		<stdlib.h>

typedef struct		s_flag_with_fct
{
  char			*(*flag_fct)(va_list *, int *);
  char			*flag;
}			t_flag_with_fct;

# include		"my_string.h"
# include		"struct_string.h"
# include		"flag_function.h"

# define		CHAR_REMOVE_OTHERS "-+0"
# define		NB_FCT 28
# define		PRIOR_CHARACTER "# +-0"
# define		NUM_FLAG_STAR 0
# define		TYPE_INTEGER "diuxXhob"
# define		CONVERT_MAJ -1
# define		CONVERT_MIN -2
# define		OCTAL -3
# define		PRINT_OCTAL 1

# define		CHARACTER 0
# define		INTEGER_POS 1
# define		INTEGER_MINUS -1
# define		INTEGER_POS_WITH_PLUS 2

# define		NO_TYPE -100
/* flag_with_fct */
t_flag_with_fct		*init_flag_with_fct();
void			free_flag_with_fct(t_flag_with_fct *);

#endif
