/*
** main.c for Main printf in /home/vuille_f/my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  2 15:33:19 2015 Florian Vuillemot
** Last update Tue Nov  3 22:36:42 2015 Florian Vuillemot
*/

#include	"my_printf.h"
#include	<string.h>
#include	<stdio.h>

int		main()
{
  char		*string;
  int		i_printf;
  int		i_my_printf;
  
  string = strdup("coucou");
  //  string[3] = 7;
    i_printf = printf("%s\n", string);
  i_my_printf = my_printf("%S\n", string);


  printf("\n\n");
  if (i_printf != i_my_printf)
    printf("%d : %d\n", i_printf, i_my_printf);
  return (0);
}
