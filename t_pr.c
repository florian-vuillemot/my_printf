/*
** my_printf.c for my_printf in /home/poloss_k/rendu/Semestre_1/PSU_2015_my_printf/newprintf
** 
** Made by kevin polossat
** Login   <poloss_k@epitech.net>
** 
** Started on  Sun Nov  8 14:09:49 2015 kevin polossat
** Last update Mon Nov 16 11:05:56 2015 Florian Vuillemot
*/

#include		<stdlib.h>
#include		<stdarg.h>
#include		"my.h"

int			main()
{
  int			i;
  int			d;

  d = 0;
  i = 0000000000000000;
  printf("EASY TEST FLAG\n\n");
  printf("%ld\n", 321312312312312321);
  my_printf("%ld\n", 321312312312312321);
  printf("%lx\n", 321312312312312321);
  my_printf("%lx\n", 321312312312312321);
  printf("%lX\n", 321312312312312321);
  my_printf("%lX\n", 321312312312312321);
  printf("%lo\n", 321312312312312321);
  my_printf("%lo\n", 321312312312312321);
  printf("%d\n", 0);
  my_printf("%d\n", 0);
  printf("%u\n", 0);
  my_printf("%u\n", 0);
  printf("%c\n", 'z');
  my_printf("%c\n", 'z');
  printf("%x\n", 3213123);
  my_printf("%x\n", 3213123);
  printf("%X\n", 3213123);
  my_printf("%X\n", 3213123);
  printf("%o\n", 3213123);
  my_printf("%o\n", 3213123);
  printf("%p\n", &i);
  my_printf("%p\n", &i);
  printf("%s\n", "salut");
  my_printf("%s\n", "salut");
  my_printf("%S\n", "\t\t\t\t\t\t\t");

  printf("EASY TEST FLAG WITH SPACE\n\n");
  printf("% ld\n", 321312312312312321);
  my_printf("% ld\n", 321312312312312321);
  printf("% li\n", 321312312312312321);
  my_printf("% li\n", 321312312312312321);
  printf("% lx\n", 321312312312312321);
  my_printf("% lx\n", 321312312312312321);
  printf("% lX\n", 321312312312312321);
  my_printf("% lX\n", 321312312312312321);
  printf("% lo\n", 321312312312312321);
  my_printf("% lo\n", 321312312312312321);
  printf("% d\n", 0);
  my_printf("% d\n", 0);
  printf("% i\n", 0);
  my_printf("% i\n", 0);
  printf("% u\n", 0);
  my_printf("% u\n", 0);
  printf("% c\n", 'z');
  my_printf("% c\n", 'z');
  printf("% x\n", 3213123);
  my_printf("% x\n", 3213123);
  printf("% X\n", 3213123);
  my_printf("% X\n", 3213123);
  printf("% o\n", 3213123);
  my_printf("% o\n", 3213123);
  printf("% p\n", &i);
  my_printf("% p\n", &i);
  printf("% s\n", "salut");
  my_printf("% s\n", "salut");
  my_printf("% S\n", "\t\t\t\t\t\t\t");
  printf("\nSEGFAULT\n");
  printf("salut%s\n", NULL);
  my_printf("salut%s\n", NULL);
  printf(NULL, 5);
  my_printf(NULL, 5);
  printf("", 5);
  my_printf("", 5);

  printf("\nTEST WITH '#'\n");
  printf("%#x%#x\n", 55, 66);
  my_printf("%#x%#x\n", 55, 66);
  printf("\n%#X%#X\n", 55, 66);
  my_printf("%#X%#X\n", 55, 66);
  printf("\n%#o%#o\n", 55, 66);
  my_printf("%#o%#o\n", 55, 66);
  printf("\n%   #   x   %    # x\n", 55, 66);
  my_printf("%   #    x   %    # x\n", 55, 66);
  printf("%#lx%#lx\n", 55, 66);
  my_printf("%#lx%#lx\n", 55, 66);
  printf("\n%#lX%#lX\n", 55, 66);
  my_printf("%#lX%#lX\n", 55, 66);
  printf("\n%#lo%#lo\n", 55, 66);
  my_printf("%#lo%#lo\n", 55, 66);
  printf("\n%   #   lx   %    # lx\n", 55, 66);
  my_printf("%   #    lx   %    # lx\n", 55, 66);
  printf("\n%#lX%#lX\n", 0, 0);
  my_printf("%#lX%#lX\n", 0, 0);
  printf("\n%#lo%#lo\n", 0, 0);
  my_printf("%#lo%#lo\n", 0, 0);

  printf("\nHARD TEST\n");
  printf("%+d\n", 5);
  my_printf("%+d\n", 5);
  my_printf("%l!\n");
  my_printf("%l!\n");
  printf("decprd%dd% dd%% d% d   !   \n", 0, -2, -3, -4); 
  my_printf("decmyd%dd% dd%% d% d   !   \n", 0, -2, -3, -4); 
  printf("decprd%Xd% Xd%% X% X   !   \n", 0, -2, -3, -4); 
  my_printf("decmyd%Xd% Xd%% X% X   !   \n", 0, -2, -3, -4); 
  printf("decprd%ud% ud%% u% u   !   \n", 0, -2, -3, -4); 
  my_printf("decmyd%ud% ud%% u% u   !   \n", 0, -2, -3, -4); 
  printf("decpru%ud% ud%% d%u   !   \n", 0, -2, -3, -4); 
  my_printf("decpru%ud% ud%% d%u   !   \n", 0, -2, -3, -4); 
  printf("decipr%i%i%i %%iii  %   i   !   \n", 0, -2, -3, -4, -99); 
  my_printf("decimy%i%i%i %%iii  %   i   !   \n", 0, -2, -3, -4, -99); 
  printf("charpr%c c%cccc %%c %c % c!c%c\n", 'a', 'b', 'z', 'x', 'i');
  my_printf("charpr%c c%cccc %%c %c % c!c%c\n", 'a', 'b', 'z', 'x', 'i');
  my_printf("binarymy%b%b b%b    b% b! b b %b b%bSALUT\n", -11000, -55, -99, -55, -66);
  my_printf("decmy%dd% dd%% % !    \n", 0, -2, -3, -4); 
  my_printf("decmy%dd% dd%% % !    \n", 0, -2, -3, -4); 
  printf("%s p%s %sp !%   s   \n", "salut", "salut", "salut", "salut");
  my_printf("%s p%s %sp !%   s   \n", "salut", "salut", "salut", "salut");
  printf("%S p%S %Sp !%   S   \n", "salut", "salut", "salut", "salut");
  my_printf("%S p%S %Sp !%   S   \n", "salu\t", "salu\n", "sa\but", "salut");
  printf("hexapr%x%x b%x    b% x! b b %x b%x\n", -011000, -55, -99, -55, -66);
  my_printf("hexamy%x%x b%x    b% x! b b %x b%x\n", -011000, -55, -99, -55, -66);
  printf("ocpr%o% od%%o %o % o o o%       o    !   \n", -01212121, -2, -3, -4, -88, -109); 
  my_printf("ocmy%o% od%%o %o % o o o%       o    !   \n", -01212121, -2, -3, -4, -88, -109);
  printf("%%%d%%%d%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", 1, 2);
  my_printf("%%%d%%%d%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", 1, 2); 
  printf("%%%d%%%d%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%d\n", 1, 2);
  my_printf("%%%d%%%d%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%d\n", 1, 2);

  printf("\nTENTATIVE DE PLANTAGE\n");
  printf("%  %     !%x\n", 5);
  my_printf("%  %     !%x\n", 5);
  my_printf("% dld%     !%x\n", 5, 10);
  printf("% dld%     !%x\n", 5, 10);
  printf("%x\n", 0); 
  printf("%o\n", 321312);
  my_printf("%o\n", 321312);
  printf("%l!!\n", 321312);
  my_printf("%l!!\n", 321312);
  printf("  ici%         \n");
  my_printf("  %         \n");
  printf("  %        s \n", "salut");
  my_printf("  %      s   l    \n", "salut");
  printf("  %      #   !\n");
  my_printf("  %       #      !\n");
  printf("  %      l        d   \n");
    my_printf("  %      l        d      \n");
  
  /*   printf("pr%+0*d\n", 5, -33); */
  /* my_printf("my%+0*d\n", 5, -33); */
  /* printf("pr%+5d\n", -33); */
  /* my_printf("my%+5d\n", -33); */
  /* printf("\nwith different type\n"); */
  /*  printf("%-d%u%i%s\n", -5, 8, -6, "%%"); */
  /*    my_printf("%-5d\n", -5, 8, -6, "%%"); */
}
