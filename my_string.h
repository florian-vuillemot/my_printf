/*
** string.h for string.h in /home/vuille_f/rendu/Piscine_C_evalexpr
**
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
**
** Started on  Wed Oct 21 09:59:41 2015 Florian Vuillemot
** Last update Tue Nov 10 20:34:47 2015 Florian Vuillemot
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

/* my_put_nbr */
char		*my_putnbr_string(long int);

/* convert_hexa */
char		*convert_hexa(unsigned long int, char *);

/* convert_octal */
char		*convert_octal(unsigned long int, char *);

/* convert_binaire */
char		*convert_binaire(unsigned long int);
#endif /* !MY_STRING_H_ */
