/*
** clean_bad_flag.c for  in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sun Nov 15 17:14:10 2015 Florian Vuillemot
** Last update Mon Nov 16 09:52:10 2015 Florian Vuillemot
*/

#include		"pars.h"

static unsigned int	found_last_char_diff_flag(t_string *string,
						  unsigned int cur)
{
  while (string->string[cur] &&
	 found_char_in_string(string->string[cur], PRIOR_CHARACTER))
    cur++;
  while (string->string[cur] <= '9' && string->string[cur] >= '0')
    cur++;
  if (string->string[cur] == '*')
    cur++;
  if (string->string[cur] == '.')
    cur++;
  while (string->string[cur] <= '9' && string->string[cur] >= '0')
    cur++;
  if (string->string[cur] == '*')
    cur++;
  return (cur);
}

t_string		*clean_past_and_bad_flag(t_string *string,
						 t_flag *flag)
{
  unsigned int		cur;

  if (!string || !string->string || !flag)
    return (NULL);
  cur = 0;
  while (string && string->string && string->string[cur])
    {
      if (string->string[cur++] == '%' &&
  	  contain_flag_fct(flag, string->string + cur) < 0)
  	{
  	  cur = found_last_char_diff_flag(string, cur);
  	  if (string && string->string[cur] &&
  	      found_char_in_string(string->string[cur], PAST_AND_BAD_FLAG))
  	    string = remove_elem_to_string(string, cur);
  	}
    }
  return (string);
}
