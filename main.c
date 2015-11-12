#include "my.h"
int main()
{
  my_printf("%-10.30d<\n", 12,"k");
  printf("%-10.30d<\n", 12,"k");
  my_printf("%-043d<\n", 12,"k");
  printf("%-043d<\n", 12,"k");
  return (0);
}
