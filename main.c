#include "my.h"
int main()
{
  my_printf("% +00032d %lu<\n", 'a',43);
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
  my_printf("%# -+d<\n", 'a');
  printf("%# -+d<\n", 'a');

  printf("partie 14:\n");
  my_printf("%1$d<\n", 'a');
  printf("%1$d<\n", 'a');
  my_printf("%2$d<\n", 'a');
  printf("%2$d<\n", 'a');

  return (0);
}
