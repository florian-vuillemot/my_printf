/*
** pars.h for parseur in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 17:03:53 2015 Florian Vuillemot
** Last update Sun Nov 15 16:09:37 2015 Florian Vuillemot
*/

#ifndef			PARSING_H_
# define		PARSING_H_

# include		"flag_and_function.h"
# include		"struct_string.h"

/* pars.c */
t_string		*parse(char *, t_flag *);
t_string		*add_zero_if_percent_dot(t_string *, t_flag *);
unsigned int		analyse_flag(t_string *, unsigned int, t_flag *);
unsigned int		clean_unnecessary_character(t_string *,
						     unsigned int,
						     unsigned int,
						     char *);

/* operator_parse */
unsigned int		clean_one_char(t_string *, unsigned int,
					 unsigned int, char);
unsigned int		clean_all_useless_character(t_string *,
						    unsigned int,
						    unsigned int);
unsigned int		remove_all_char_in_string(t_string *,
						  unsigned int, unsigned int,
						  char);
unsigned int		remove_elem1_if_elem0(t_string *,
					      unsigned int, unsigned int,
					      char *);
unsigned int		make_string_in_order(t_string *,
					     unsigned int, unsigned int);
#endif
