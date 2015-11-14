#include "my.h"
int main()
{
  char		*string;

  string = strdup("coucou");
  string[1] = 3;
  my_printf("%#32c<\n", *string);
  printf("%#32c<\n", *string);
  my_printf("%# 26c<\n", *string);
  printf("%# 26c<\n", *string);

  printf("partie 1:\n");
  my_printf("%# 032c<\n", *string);
  printf("%# 032c<\n", *string);
  my_printf("%#0 +26c<\n", *string);
  printf("%#0 +26c<\n", *string);
  my_printf("%# +26c<\n", *string);
  printf("%# +26c<\n", *string);

  printf("partie 2:\n");
  my_printf("%#032c<\n", *string);
  printf("%#032c<\n", *string);
  my_printf("%#2.26c<\n", *string);
  printf("%#2.26c<\n", *string);

  printf("partie 32:\n");
  my_printf("%#32.2c<\n", *string);
  printf("%#32.2c<\n", *string);
  my_printf("%#-32.2c<\n", *string);
  printf("%#-32.2c<\n", *string);
  my_printf("%#+32.2c<\n", *string);
  printf("%#+32.2c<\n", *string);
  my_printf("%# +32.2c<\n", *string);
  printf("%# +32.2c<\n", *string);

  printf("partie 4:\n");
  my_printf("%# 032.2c<\n", *string);
  printf("%# 032.2c<\n", *string);
  my_printf("%# -32.2c<\n", *string);
  printf("%# -32.2c<\n", *string);

  printf("partie 5:\n");
  my_printf("%#+032.2c<\n", *string);
  printf("%#+032.2c<\n", *string);
  my_printf("%# +-32.2c<\n", *string);
  printf("%# -+32.2c<\n", *string);

  printf("partie 6:\n");
  my_printf("%#-+032.2c<\n", *string);
  printf("%#-+032.2c<\n", *string);
  my_printf("%#-+32.2c<\n", *string);
  printf("%#-+32.2c<\n", *string);

  printf("partie 7:\n");
  my_printf("%#-032c<\n", *string);
  printf("%#-032c<\n", *string);
  my_printf("%#-2.26c<\n", *string);
  printf("%#-2.26c<\n", *string);

  printf("partie 8:\n");
  my_printf("%#.32c<\n", *string);
  printf("%#.32c<\n", *string);
  my_printf("%# .26c<\n", *string);
  printf("%# .26c<\n", *string);

  printf("partie 9:\n");
  my_printf("%#+.32c<\n", *string);
  printf("%#+.32c<\n", *string);
  my_printf("%#-.26c<\n", *string);
  printf("%#-.26c<\n", *string);

  printf("partie 10:\n");
  my_printf("%# +.32c<\n", *string);
  printf("%# +.32c<\n", *string);
  my_printf("%# -.26c<\n", *string);
  printf("%# -.26c<\n", *string);

  printf("partie 11:\n");
  my_printf("%#c<\n", *string);
  printf("%#c<\n", *string);
  my_printf("%# c<\n", *string);
  printf("%# c<\n", *string);

  printf("partie 12:\n");
  my_printf("%#+c<\n", *string);
  printf("%#+c<\n", *string);
  my_printf("%# +c<\n", *string);
  printf("%# +c<\n", *string);

  printf("partie 132:\n");
  my_printf("%#-+c<\n", *string);
  printf("%#+-c<\n", *string);
  my_printf("%# -+c<\n", *string);
  printf("%# -+c<\n", *string);

  return (0);
}
