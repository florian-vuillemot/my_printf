#include "my.h"
int main()
{
  my_printf("%#32X<\n", 32);
  printf("%#32X<\n", 32);
  my_printf("%# 26X<\n", 32);
  printf("%# 26X<\n", 32);

  printf("partie 1:\n");
  my_printf("%# 032X<\n", 32);
  printf("%# 032X<\n", 32);
  my_printf("%#0 +26X<\n", 32);
  printf("%#0 +26X<\n", 32);
  my_printf("%# +26X<\n", 32);
  printf("%# +26X<\n", 32);

  printf("partie 2:\n");
  my_printf("%#032X<\n", 32);
  printf("%#032X<\n", 32);
  my_printf("%#10.26X<\n", 32);
  printf("%#10.26X<\n", 32);

  printf("partie 3:\n");
  my_printf("%#32.10X<\n", 32);
  printf("%#32.10X<\n", 32);
  my_printf("%#-32.10X<\n", 32);
  printf("%#-32.10X<\n", 32);
  my_printf("%#+32.10X<\n", 32);
  printf("%#+32.10X<\n", 32);
  my_printf("%# +32.10X<\n", 32);
  printf("%# +32.10X<\n", 32);

  printf("partie 4:\n");
  my_printf("%# 032.10X<\n", 32);
  printf("%# 032.10X<\n", 32);
  my_printf("%# -32.10X<\n", 32);
  printf("%# -32.10X<\n", 32);

  printf("partie 5:\n");
  my_printf("%#+032.10X<\n", 32);
  printf("%#+032.10X<\n", 32);
  my_printf("%# +-32.10X<\n", 32);
  printf("%# -+32.10X<\n", 32);

  printf("partie 6:\n");
  my_printf("%#-+032.10X<\n", 32);
  printf("%#-+032.10X<\n", 32);
  my_printf("%#-+32.10X<\n", 32);
  printf("%#-+32.10X<\n", 32);

  printf("partie 7:\n");
  my_printf("%#-032X<\n", 32);
  printf("%#-032X<\n", 32);
  my_printf("%#-10.26X<\n", 32);
  printf("%#-10.26X<\n", 32);

  printf("partie 8:\n");
  my_printf("%#.32X<\n", 32);
  printf("%#.32X<\n", 32);
  my_printf("%# .26X<\n", 32);
  printf("%# .26X<\n", 32);

  printf("partie 9:\n");
  my_printf("%#+.32X<\n", 32);
  printf("%#+.32X<\n", 32);
  my_printf("%#-.26X<\n", 32);
  printf("%#-.26X<\n", 32);

  printf("partie 10:\n");
  my_printf("%# +.32X<\n", 32);
  printf("%# +.32X<\n", 32);
  my_printf("%# -.26X<\n", 32);
  printf("%# -.26X<\n", 32);

  printf("partie 11:\n");
  my_printf("%#X<\n", 32);
  printf("%#X<\n", 32);
  my_printf("%# X<\n", 32);
  printf("%# X<\n", 32);

  printf("partie 12:\n");
  my_printf("%#+X<\n", 32);
  printf("%#+X<\n", 32);
  my_printf("%# +X<\n", 32);
  printf("%# +X<\n", 32);

  printf("partie 13:\n");
  my_printf("%#-+X<\n", 32);
  printf("%#+-X<\n", 32);
  my_printf("%# -+X<\n", 32);
  printf("%# -+X<\n", 32);

  return (0);
}
