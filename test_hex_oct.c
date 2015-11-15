#include "my.h"
int main()
{
  my_printf("%#320.*;d %15d %10d %24d %111d %123<\n", 32,9,8,7,6,5,4);
  printf("%#321.*;d %15d %10d %24d %111d %123<\n", 32,9,8,7,6,5,4);
  printf("kk\n");
  printf("%#320d %15d %10d %24d %111d %123<\n", 32,9,8,7,6,5,4);
  my_printf("%# 26d<\n", 32);
  printf("%# 26d<\n", 32);

  printf("partie 1:\n");
  my_printf("%# 032d<\n", 32);
  printf("%# 032d<\n", 32);
  my_printf("%#0 +26d<\n", 32);
  printf("%#0 +26d<\n", 32);
  my_printf("%# +26d<\n", 32);
  printf("%# +26d<\n", 32);

  printf("partie 2:\n");
  my_printf("%#032d<\n", 32);
  printf("%#032d<\n", 32);
  my_printf("%#10.26d<\n", 32);
  printf("%#10.26d<\n", 32);

  printf("partie 3:\n");
  my_printf("%#32.10d<\n", 32);
  printf("%#32.10d<\n", 32);
  my_printf("%#-32.10d<\n", 32);
  printf("%#-32.10d<\n", 32);
  my_printf("%#+32.10d<\n", 32);
  printf("%#+32.10d<\n", 32);
  my_printf("%# +32.10d<\n", 32);
  printf("%# +32.10d<\n", 32);

  printf("partie 4:\n");
  my_printf("%# 032.10d<\n", 32);
  printf("%# 032.10d<\n", 32);
  my_printf("%# -32.10d<\n", 32);
  printf("%# -32.10d<\n", 32);

  printf("partie 5:\n");
  my_printf("%#+032.10d<\n", 32);
  printf("%#+032.10d<\n", 32);
  my_printf("%# +-32.10d<\n", 32);
  printf("%# -+32.10d<\n", 32);

  printf("partie 6:\n");
  my_printf("%#-+032.10d<\n", 32);
  printf("%#-+032.10d<\n", 32);
  my_printf("%#-+32.10d<\n", 32);
  printf("%#-+32.10d<\n", 32);

  printf("partie 7:\n");
  my_printf("%#-032d<\n", 32);
  printf("%#-032d<\n", 32);
  my_printf("%#-10.26d<\n", 32);
  printf("%#-10.26d<\n", 32);

  printf("partie 8:\n");
  my_printf("%#.32d<\n", 32);
  printf("%#.32d<\n", 32);
  my_printf("%# .26d<\n", 32);
  printf("%# .26d<\n", 32);

  printf("partie 9:\n");
  my_printf("%#+.32d<\n", 32);
  printf("%#+.32d<\n", 32);
  my_printf("%#-.26d<\n", 32);
  printf("%#-.26d<\n", 32);

  printf("partie 10:\n");
  my_printf("%# +.32d<\n", 32);
  printf("%# +.32d<\n", 32);
  my_printf("%# -.26d<\n", 32);
  printf("%# -.26d<\n", 32);

  printf("partie 11:\n");
  my_printf("%#d<\n", 32);
  printf("%#d<\n", 32);
  my_printf("%# d<\n", 32);
  printf("%# d<\n", 32);

  printf("partie 12:\n");
  my_printf("%#+d<\n", 32);
  printf("%#+d<\n", 32);
  my_printf("%# +d<\n", 32);
  printf("%# +d<\n", 32);

  printf("partie 13:\n");
  my_printf("%#-+d<\n", 32);
  printf("%#+-d<\n", 32);
  my_printf("%# -+d<\n", 32);
  printf("%# -+d<\n", 32);

  return (0);
}
