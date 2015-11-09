/*
** operator_parse.c for operator in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 17:49:16 2015 Florian Vuillemot
** Last update Sun Nov  8 11:07:20 2015 Florian Vuillemot
*/

#include		"pars.h"

unsigned int		clean_one_char(t_string *string, unsigned int beg,
				       unsigned int end,
				       char character_to_control)
{
  int			char_present;

  if (!string || !string->string)
    return (0);
  char_present = 0;
  while (string->string[beg] && beg < end && char_present == 0)
    {
      if (string->string[beg] == character_to_control)
	char_present = 1;
      beg = beg + 1;
    }
  while (string->string[beg] && beg < end)
    {
      if (string->string[beg] == character_to_control)
	{
	  remove_elem_to_string(string, beg);
	  end = end - 1;
	}
      else
	beg = beg + 1;
    }
  return (end);
}

unsigned int		clean_all_useless_character(t_string *string,
						    unsigned int beg,
						    unsigned int end)
{
  int			j;

  while (beg < end && string->string[beg])
    {
      if ((j =
	   (get_place_char_in_string(string->string[beg],
				     CHAR_REMOVE_OTHERS)) > -1))
	  while (CHAR_REMOVE_OTHERS[j])
	    {
	      end = remove_all_char_in_string(string, beg, end,
					      CHAR_REMOVE_OTHERS[j]);
	      j = j + 1;
	    }
      beg = beg + 1;
    }
  return (end);
}


/******************************* UTILE ?? ***********************************/
unsigned int		remove_all_char_in_string(t_string *string,
						  unsigned int beg,
						  unsigned int end,
						  char remove)
{
  if (!string || !string->string)
    return (0);
  while (beg < end && string->string[beg])
    {
      if (string->string[beg] == remove)
	{
	  remove_elem_to_string(string, beg);
	  end = end - 1;
	}
      beg = beg + 1;
    }
  return (end);
}

unsigned int		remove_elem1_if_elem0(t_string *string,
					     unsigned int beg,
					     unsigned int end,
					     char *elems)
{
  int			zero;

  if (!string || !string->string || !elems || !elems[0] || !elems[1])
    return (0);
  zero = -1;
  while (beg < end && string->string[beg])
    {
      if (string->string[beg] == elems[0])
	{
	  if (zero > -1 && remove_elem_to_string(string, zero))
	    return (end - 1);
	  zero = -2;
	}
      if (string->string[beg] == elems[1])
	{
	  if (zero != -1 && remove_elem_to_string(string, beg))
	    return (end - 1);
	  zero = beg;
	}
      beg = beg + 1;
    }
  return (end);
}

unsigned int		make_string_in_order(t_string *string,
					     unsigned int beg,
					     unsigned int end)
{
  int			i;
  int			place;
  char			end_of_string;

  if (!string || !string->string)
    return (0);
  i = -1;
  end_of_string = string->string[end];
  string->string[end] = '\0';
  while (PRIOR_CHARACTER[(i = i + 1)] && beg < end && string->string[beg])
    {
      if ((place =
	   get_place_char_in_string(PRIOR_CHARACTER[i],
				    string->string + beg)) > -1)
	{
	  remove_elem_to_string(string, place + beg);
	  add_elem_to_string(string, beg, PRIOR_CHARACTER[i]);
	  beg = beg + 1;
	}
    }
  string->string[end] = end_of_string;
  return (end);
}
