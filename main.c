/*
** main.c for Main printf in /home/vuille_f/my_printf
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Nov  2 15:33:19 2015 Florian Vuillemot
** Last update Wed Nov  4 18:46:39 2015 Florian Vuillemot
*/

#include	"my_printf.h"
#include	<string.h>
#include	<stdio.h>

int		main()
{
  char		*string, *string1, *string2;
  int		i_printf;
  int		i_my_printf;
  double		i_te;

  i_te = 0.0;
  string = strdup("coucou");
  string[3] = 127;
  string1 = strdup("Flor");
  string2 = strdup("Florian");
  //  string[3] = 7;
  //  i_printf = printf("%++---000010ck\n", 'c');// string1, string2);
  i_my_printf = my_printf("%f\n", 10.09); //, string1, string2);


  printf("\n\n");
  if (i_printf != i_my_printf)
    printf("%d : %d\n", i_printf, i_my_printf);
  return (0);
}
