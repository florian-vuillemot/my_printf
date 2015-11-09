/*
** read_string.c for read in /home/vuille_f/PSU_2015_my_printf/string
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 15:38:25 2015 Florian Vuillemot
** Last update Sat Nov  7 15:51:13 2015 Florian Vuillemot
*/

#include		"struct_string.h"

void			print_string(t_string *string)
{
  if (!string || !string->string)
    return ;
  write(1, string->string, string->cursor);
}
