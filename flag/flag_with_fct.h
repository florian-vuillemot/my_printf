/*
** flag_with_fct.h for fct in /home/vuille_f/PSU_2015_my_printf/flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 18:55:41 2015 Florian Vuillemot
** Last update Mon Nov  9 23:37:06 2015 Florian Vuillemot
*/

#ifndef			FLAG_WITH_FCT_H_
# define		FLAG_WITH_FCT_H_

# include		<stdarg.h>
# include		<stdlib.h>
# include		"my_string.h"
# include		"struct_string.h"

# define		CHAR_REMOVE_OTHERS "-+0"
# define		NB_FCT 2
# define		PRIOR_CHARACTER "# +-0"
# define		NUM_FLAG_STAR 0
# define		TYPE_INTEGER "dixXho"

# define		CHARACTER 0
# define		INTEGER_POS 1
# define		INTEGER_POS_WITH_PLUS 2

typedef struct		s_flag_with_fct
{
  char			*(*flag_fct)(va_list *, int *);
  char			*flag;
}			t_flag_with_fct;

/* flag_with_fct */
t_flag_with_fct		*init_flag_with_fct();
void			free_flag_with_fct(t_flag_with_fct *);

#endif
