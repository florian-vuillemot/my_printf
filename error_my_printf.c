/*
** error_my_printf.c for error in /home/vuille_f/PSU_2015_my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Wed Nov  4 14:46:51 2015 Florian Vuillemot
** Last update Wed Nov  4 14:49:17 2015 Florian Vuillemot
*/

#include	"my_string.h"

int		error_my_printf()
{
  write(2, ERROR_MSG, sizeof(ERROR_MSG));
  return (0);
}
