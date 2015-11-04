/*
** string.h for string.h in /home/vuille_f/rendu/Piscine_C_evalexpr
**
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
**
** Started on  Wed Oct 21 09:59:41 2015 Florian Vuillemot
** Last update Wed Nov  4 17:53:25 2015 Florian Vuillemot
*/

#ifndef		MY_STRING_H_
# define	MY_STRING_H_

# include	<unistd.h>
# include	<stdlib.h>

# define	ERROR_MSG "Error in my_printf\n"
# define	OVERFLOW "Overflow\n"

/* my_string.c */
void		my_putchar(char);
void		my_putstr(char *);
unsigned int	my_strlen(char *);
char		*my_strdup(char *);
int		error_my_printf();

/* my_getnbr.c */
int		my_getnbr(char *);
void		put_space_and_zero(int, int);
void		analyse_space_and_zero_in_string(int *, int *,
						 char *, int *);
int		space_or_zero_in_front_of_the_string(char *);

#endif /* !MY_STRING_H_ */
