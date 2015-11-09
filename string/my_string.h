/*
** string.h for string.h in /home/vuille_f/rendu/Piscine_C_evalexpr
**
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
**
** Started on  Wed Oct 21 09:59:41 2015 Florian Vuillemot
** Last update Sun Nov  8 17:44:53 2015 Florian Vuillemot
*/

#ifndef		MY_STRING_H_
# define	MY_STRING_H_

# include	<unistd.h>
# include	<stdlib.h>

# define	MAX(a, b) ((a) > (b) ? (a) : (b))

/* my_string.c */
void		my_putchar(char);
void		my_putstr(char *);
unsigned int	my_strlen(char *);
char		*my_strdup(char *);

/* my_comp_string */
int		my_strcmp(char *, char *);
int		found_char_in_string(char, char *);
int		get_place_char_in_string(char, char *);

/* my_getnbr */
int		my_getnbr(char *);
#endif /* !MY_STRING_H_ */