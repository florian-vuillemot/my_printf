/*
** flag.h for flag in /home/vuille_f/PSU_2015_my_printf/flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 18:45:51 2015 Florian Vuillemot
** Last update Sun Nov  8 20:27:20 2015 Florian Vuillemot
*/

#ifndef			FLAG_AND_FCT_H_
# define		FLAG_AND_FCT_H_

# include		<stdlib.h>
# include		"flag_with_fct.h"

typedef struct		s_flag
{
  t_flag_with_fct	*flag_and_fct;
  char			*autorized_with_flag;
}			t_flag;

/* flag_and_fct */
t_flag			*init_flag_and_fct();
void			free_flag_and_fct(t_flag *);

/* use_flag */
int			cmp_string_and_flag(t_flag *, char *);
int			contain_flag_fct(t_flag *, char *);
int			contain_star(char *);

#endif /* !FLAG_AND_FCT_H_ */
