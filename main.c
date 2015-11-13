#include "my.h"
int main()
{
  my_printf("%32p<\n", "k");
  printf("%32p<\n", "k");
  my_printf("% 26p<\n", "k");
  printf("% 26p<\n", "k");

  printf("partie 1:\n");
  my_printf("% 032p<\n", "k");
  printf("% 032p<\n", "k");
  my_printf("%0 +26p<\n", "k");
  printf("%0 +26p<\n", "k");
  my_printf("% +26p<\n", "k");
  printf("% +26p<\n", "k");

  printf("partie 2:\n");
  my_printf("%032p<\n", "k");
  printf("%032p<\n", "k");
  my_printf("%10.26p<\n", "k");
  printf("%10.26p<\n", "k");

  printf("partie 3:\n");
  my_printf("%32.10p<\n", "k");
  printf("%32.10p<\n", "k");
  my_printf("%-32.10p<\n", "k");
  printf("%-32.10p<\n", "k");
  my_printf("%+32.10p<\n", "k");
  printf("%+32.10p<\n", "k");
  my_printf("% +32.10p<\n", "k");
  printf("% +32.10p<\n", "k");

  printf("partie 4:\n");
  my_printf("%032.10p<\n", "k");
  printf("%032.10p<\n", "k");
  my_printf("% -32.10p<\n", "k");
  printf("% -32.10p<\n", "k");

  printf("partie 5:\n");
  my_printf("%+032.10p<\n", "k");
  printf("%+032.10p<\n", "k");
  my_printf("% +-32.10p<\n", "k");
  printf("% -+32.10p<\n", "k");

  printf("partie 6:\n");
  my_printf("%-+032.10p<\n", "k");
  printf("%-+032.10p<\n", "k");
  my_printf("% -+32.10p<\n", "k");
  printf("% -+32.10p<\n", "k");

  printf("partie 7:\n");
  my_printf("%-032p<\n", "k");
  printf("%-032p<\n", "k");
  my_printf("%-10.26p<\n", "k");
  printf("%-10.26p<\n", "k");

  printf("partie 8:\n");
  my_printf("%.32p<\n", "k");
  printf("%.32p<\n", "k");
  my_printf("% .26p<\n", "k");
  printf("% .26p<\n", "k");

  printf("partie 9:\n");
  my_printf("%+.32p<\n", "k");
  printf("%+.32p<\n", "k");
  my_printf("%-.26p<\n", "k");
  printf("%-.26p<\n", "k");

  printf("partie 10:\n");
  my_printf("% +.32p<\n", "k");
  printf("% +.32p<\n", "k");
  my_printf("% -.26p<\n", "k");
  printf("% -.26p<\n", "k");

  printf("partie 11:\n");
  my_printf("%p<\n", "k");
  printf("%p<\n", "k");
  my_printf("% p<\n", "k");
  printf("% p<\n", "k");

  printf("partie 12:\n");
  my_printf("%+p<\n", "k");
  printf("%+p<\n", "k");
  my_printf("% +p<\n", "k");
  printf("% +p<\n", "k");

  printf("partie 13:\n");
  my_printf("%-+p<\n", "k");
  printf("%+-p<\n", "k");
  my_printf("% -+p<\n", "k");
  printf("% -+p<\n", "k");

  return (0);
}
