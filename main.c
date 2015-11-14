#include "my.h"
int main()
{
  my_printf("%#32ld<\n", 32);
  printf("%#32ld<\n", 32);
  my_printf("%# 26ld<\n", 32);
  printf("%# 26ld<\n", 32);

  printf("partie 1:\n");
  my_printf("%# 032ld<\n", 32);
  printf("%# 032ld<\n", 32);
  my_printf("%#0 +26ld<\n", 32);
  printf("%#0 +26ld<\n", 32);
  my_printf("%# +26ld<\n", 32);
  printf("%# +26ld<\n", 32);

  printf("partie 2:\n");
  my_printf("%#032ld<\n", 32);
  printf("%#032ld<\n", 32);
  my_printf("%#10.26ld<\n", 32);
  printf("%#10.26ld<\n", 32);

  printf("partie 3:\n");
  my_printf("%#32.10ld<\n", 32);
  printf("%#32.10ld<\n", 32);
  my_printf("%#-32.10ld<\n", 32);
  printf("%#-32.10ld<\n", 32);
  my_printf("%#+32.10ld<\n", 32);
  printf("%#+32.10ld<\n", 32);
  my_printf("%# +32.10ld<\n", 32);
  printf("%# +32.10ld<\n", 32);

  printf("partie 4:\n");
  my_printf("%# 032.10ld<\n", 32);
  printf("%# 032.10ld<\n", 32);
  my_printf("%# -32.10ld<\n", 32);
  printf("%# -32.10ld<\n", 32);

  printf("partie 5:\n");
  my_printf("%#+032.10ld<\n", 32);
  printf("%#+032.10ld<\n", 32);
  my_printf("%# +-32.10ld<\n", 32);
  printf("%# -+32.10ld<\n", 32);

  printf("partie 6:\n");
  my_printf("%#-+032.10ld<\n", 32);
  printf("%#-+032.10ld<\n", 32);
  my_printf("%#-+32.10ld<\n", 32);
  printf("%#-+32.10ld<\n", 32);

  printf("partie 7:\n");
  my_printf("%#-032ld<\n", 32);
  printf("%#-032ld<\n", 32);
  my_printf("%#-10.26ld<\n", 32);
  printf("%#-10.26ld<\n", 32);

  printf("partie 8:\n");
  my_printf("%#.32ld<\n", 32);
  printf("%#.32ld<\n", 32);
  my_printf("%# .26ld<\n", 32);
  printf("%# .26ld<\n", 32);

  printf("partie 9:\n");
  my_printf("%#+.32ld<\n", 32);
  printf("%#+.32ld<\n", 32);
  my_printf("%#-.26ld<\n", 32);
  printf("%#-.26ld<\n", 32);

  printf("partie 10:\n");
  my_printf("%# +.32ld<\n", 32);
  printf("%# +.32ld<\n", 32);
  my_printf("%# -.26ld<\n", 32);
  printf("%# -.26ld<\n", 32);

  printf("partie 11:\n");
  my_printf("%#ld<\n", 32);
  printf("%#ld<\n", 32);
  my_printf("%# ld<\n", 32);
  printf("%# ld<\n", 32);

  printf("partie 12:\n");
  my_printf("%#+ld<\n", 32);
  printf("%#+ld<\n", 32);
  my_printf("%# +ld<\n", 32);
  printf("%# +ld<\n", 32);

  printf("partie 13:\n");
  my_printf("%#-+ld<\n", 32);
  printf("%#+-ld<\n", 32);
  my_printf("%# -+ld<\n", 32);
  printf("%# -+ld<\n", 32);

  return (0);
}
