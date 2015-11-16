/*
** use_flag.c for use_falg in /home/vuille_f/PSU_2015_my_printf/flag
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 19:30:19 2015 Florian Vuillemot
** Last update Mon Nov 16 09:29:15 2015 Florian Vuillemot
*/

#include		"flag_and_function.h"

int			cmp_string_and_flag(t_flag *flag, char *str)
{
  int			curs;
  int			i;

  if (!flag || !flag->flag_and_fct || !str)
    return (-1);
  curs = 0;
  while (flag->flag_and_fct[curs].flag)
    {
      i = 0;
      while (flag->flag_and_fct[curs].flag[i] && str[i] &&
	     flag->flag_and_fct[curs].flag[i] == str[i])
	i = i + 1;
      if (flag->flag_and_fct[curs].flag[i] == '\0')
	return (curs);
      curs = curs + 1;
    }
  return (-1);
}

int			contain_flag_fct(t_flag *flag, char *str)
{
  if (!flag || !flag->flag_and_fct || !str)
    return (-1);
  while (*str && found_char_in_string(*str, PRIOR_CHARACTER))
    str = str + 1;
  while (*str <= '9' && *str >= '0')
    str = str + 1;
  if (*str == '.')
    str = str + 1;
  while (*str <= '9' && *str >= '0')
    str = str + 1;
  return (cmp_string_and_flag(flag, str));
}

int			contain_flag_fct_star(t_flag *flag, char *str)
{
  if (!flag || !flag->flag_and_fct || !str)
    return (-1);
  while (*str && found_char_in_string(*str, PRIOR_CHARACTER))
    str = str + 1;
  while (*str <= '9' && *str >= '0')
    str = str + 1;
  if (*str == '*')
    str = str + 1;
  if (*str == '.')
    str = str + 1;
  else
    return (cmp_string_and_flag(flag, str));
  while (*str <= '9' && *str >= '0')
    str = str + 1;
  if (*str == '*')
    str = str + 1;
  return (cmp_string_and_flag(flag, str));
}

int			contain_star(char *str)
{
  int			nb;

  if (!str)
    return (-1);
  nb = 0;
  while (*str && found_char_in_string(*str, PRIOR_CHARACTER))
    str = str + 1;
  if (*str == '*')
    {
      nb++;
      str = str + 1;
    }
  else
    while (*str <= '9' && *str >= '0')
      str = str + 1;
  if (*str == '.' || *str == '$')
    str = str + 1;
  if (*str == '*')
    nb++;
  return (nb);
}

int			contain_flag_all_star(t_flag *flag, char *str)
{
  if (!flag || !flag->flag_and_fct || !str)
    return (-1);
  while (*str && found_char_in_string(*str, PRIOR_CHARACTER))
    str = str + 1;
  if (*str == '*')
    while (*str <= '9' && *str >= '0')
      str = str + 1;
  else
    while (*str == '*')
      str = str + 1;
  if (*str == '.')
    str = str + 1;
  if (*str != '*')
    while (*str <= '9' && *str >= '0')
      str = str + 1;
  else
    while (*str == '*')
      str = str + 1;
  return (cmp_string_and_flag(flag, str));
}
