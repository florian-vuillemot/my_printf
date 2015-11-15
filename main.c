#include "my.h"
#include <stdio.h>
int main()
{unsigned long int i = 1;
  my_printf("%#lx<\n", i << (sizeof(long int) * 8 - 1));
  printf("%#lx<\n", i << (sizeof(long int) * 8 - 1));
  my_printf("%# 26d<\n", 'a');
  printf("%*3$d<\n", -20,'d',5,5);

  printf("partie 1:\n");
  my_printf("%# 032d<\n", 'a');
  printf("%# 032d<\n", 'a');
  my_printf("%#0 +26d<\n", 'a');
  printf("%#0 +26d<\n", 'a');
  my_printf("%# +26d<\n", 'a');
  printf("%# +26d<\n", 'a');

  printf("partie 2:\n");
  my_printf("%#032d<\n", 'a');
  printf("%#032d<\n", 'a');
  my_printf("%#10.26d<\n", 'a');
  printf("%#10.26d<\n", 'a');

  printf("partie 3:\n");
  my_printf("%#32.10d<\n", 'a');
  printf("%#32.10d<\n", 'a');
  my_printf("%#-32.10d<\n", 'a');
  printf("%#-32.10d<\n", 'a');
  my_printf("%#+32.10d<\n", 'a');
  printf("%#+32.10d<\n", 'a');
  my_printf("%# +32.10d<\n", 'a');
  printf("%# +32.10d<\n", 'a');

  printf("partie 4:\n");
  my_printf("%# 032.10d<\n", 'a');
  printf("%# 032.10d<\n", 'a');
  my_printf("%# -32.10d<\n", 'a');
  printf("%# -32.10d<\n", 'a');

  printf("partie 5:\n");
  my_printf("%#+032.10d<\n", 'a');
  printf("%#+032.10d<\n", 'a');
  my_printf("%# +-32.10d<\n", 'a');
  printf("%# -+32.10d<\n", 'a');

  printf("partie 6:\n");
  my_printf("%#-+032.10d<\n", 'a');
  printf("%#-+032.10d<\n", 'a');
  my_printf("%#-+32.10d<\n", 'a');
  printf("%#-+32.10d<\n", 'a');

  printf("partie 7:\n");
  my_printf("%#-032d<\n", 'a');
  printf("%#-032d<\n", 'a');
  my_printf("%#-10.26d<\n", 'a');
  printf("%#-10.26d<\n", 'a');

  printf("partie 8:\n");
  my_printf("%#.32d<\n", 'a');
  printf("%#.32d<\n", 'a');
  my_printf("%# .26d<\n", 'a');
  printf("%# .26d<\n", 'a');

  printf("partie 9:\n");
  my_printf("%#+.32d<\n", 'a');


  printf("%#+.32d<\n", 'a');
  my_printf("%#-.26d<\n", 'a');
  printf("%#-.26d<\n", 'a');

  printf("partie 10:\n");
  my_printf("%# +.32d<\n", 'a');
  printf("%# +.32d<\n", 'a');
  my_printf("%# -.26d<\n", 'a');
  printf("%# -.26d<\n", 'a');

  printf("partie 11:\n");
  my_printf("%#d<\n", 'a');
  printf("%#d<\n", 'a');
  my_printf("%# d<\n", 'a');
  printf("%# d<\n", 'a');

  printf("partie 12:\n");
  my_printf("%#+d<\n", 'a');
  printf("%#+d<\n", 'a');
  my_printf("%# +d<\n", 'a');
  printf("%# +d<\n", 'a');

  printf("partie 13:\n");
  my_printf("%#-+d<\n", 'a');
  printf("%#+-d<\n", 'a');
  my_printf("%# -+d< %d%d %d\n", 'a',10,11,12);
  printf("%# -+d<\n", 'a');
  /* printf("partie 14:\n"); */
  /* my_printf("%1$d %d %d %d %d %2$d %d<\n", 'a',34,32); */
  /* printf("%10$c %d <\n", 'a', 34); */
  /* my_printf("%2$d %c %c %c<\n", 'a','1','2','3'); */
  /* printf("%2$o %c %c %c<\n", 'a','1','2','3'); */
  /* printf("%2$d<\n", 'a', 32); */

  my_printf("%s%%%d%dasteck%s","astek",32,3,"moulkjinl","moulinnete");
  printf("\n");
  printf("%s%%%d%s","astek",42,"moulinnete");
  printf("\n");
  //  printf("%*.*d\n",10,15,20);
 
     printf(">%d%d%*d%*.*;%*d\n",10,20,3,50,234,43,11,10,22,32);
  my_printf(">%d%d%*d%*.*;%*d\n",10,20,3,50,234,43,11,10,22,32,0);
  return (0);
}
