/*
** struct_string.h for struct string in /home/vuille_f
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 14:30:47 2015 Florian Vuillemot
** Last update Sat Nov 14 22:11:32 2015 Florian Vuillemot
*/

#ifndef			STRUCT_STRING_H_
# define		STRUCT_STRING_H_

# include		<stdlib.h>
# include		<stdio.h>
# include		"my_string.h"

typedef struct		s_string
{
  char			*string;
  unsigned int		cursor;
  unsigned int		len;
}			t_string;

/* init_struct_string */
t_string		*create_string(char *);
t_string		*free_string(t_string *);
t_string		*realloc_string(t_string *);

/* write_on_string */
t_string		*conca_string(t_string *, t_string *);
t_string		*add_string(t_string *, char *);
t_string		*insert_string(t_string *, char *, unsigned int);

/* read_string */
void			print_string(t_string *);

/* mouv_elem_string */
t_string		*add_elem_to_string(t_string *, unsigned int, char);
t_string		*remove_elem_to_string(t_string *, unsigned int);

#endif /* !STRUCT_STRING_H_ */
