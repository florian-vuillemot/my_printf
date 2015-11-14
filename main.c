#include "my.h"
int main()
{
  my_printf("%ld<\n", -34,43);
  printf("% +00032d %lu<\n", 'a',43);
  my_printf("%# 26d<\n", 'a');
  printf("%# 26d<\n", 'a');

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

  my_printf("%s%%%d%s","astek",32,"moulkjinl","moulinnete");
  printf("\n");
  printf("%s%%%d%s","astek",42,"moulinnete");
  printf("\n");

  return (0);
}
