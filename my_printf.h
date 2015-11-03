/*
** my_printf.h for my_printf in /home/vuille_f/my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  2 15:34:50 2015 Florian Vuillemot
** Last update Tue Nov  3 20:23:34 2015 Florian Vuillemot
*/

#ifndef		MY_PRINTF_H_
# define	MY_PRINTF_H_

# include	<stdarg.h>
# include	<stdlib.h>
# include	"print_flags.h"

typedef struct	s_flag_and_fct
{
  char		*flag;
  int		(*flag_fct)(char *, int *, va_list *);
}		t_flag_and_fct;

/* my_printf.c */
int		cmp_flags(char *, char *);
int		my_printf(char *, ...);

#endif /* !MY_PRINTF_H_ */
