#include "my.h"
int main()
{
  my_printf("% -32p<\n", "k");
  printf("% -32p<\n", "k");
  my_printf("% -5.20p<\n", "k");
  printf("% -5.20p<\n", "k");
  return (0);
}
