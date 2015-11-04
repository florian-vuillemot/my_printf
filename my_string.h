/*
** string.h for string.h in /home/vuille_f/rendu/Piscine_C_evalexpr
**
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
**
** Started on  Wed Oct 21 09:59:41 2015 Florian Vuillemot
** Last update Wed Nov  4 14:52:28 2015 Florian Vuillemot
*/

#ifndef		MY_STRING_H_
# define	MY_STRING_H_

# include	<unistd.h>
# include	<stdlib.h>

# define	ERROR_MSG "Error in my_printf\n"

/* my_string.c */
void		my_putchar(char);
void		my_putstr(char *);
unsigned int	my_strlen(char *);
char		*my_strdup(char *);

/* my_putnbr_base.c */
int		my_putnbr_base(int, char *);

#endif /* !MY_STRING_H_ */