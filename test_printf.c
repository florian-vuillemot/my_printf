#include <stdlib.h>
#include <stdio.h>

int main()
{
  int i = 40;
  printf("%l;  0 %+-* end\n", -12,1,10,51,"cooc",3,43);
  my_printf("%l;  0 %+-* end\n", -12,1,10,51,"cooc",3,43);
  my_printf("%l;  0 %+* end\n", 12,1,10,51,"cooc",3,43);
  my_printf("%l;  0 %+-* end\n", 12,1,10,51,"cooc",3,43);
  my_printf("%l;  0 %+* end\n", -12,1,10,51,"cooc",3,43);
  my_printf("%l;  0 %+----* end\n", 12,1,10,51,"cooc",3,43);
  my_printf("%l;  0 %+-* end\n", 12,1,10,51,"cooc",3,43);
  printf("%-+++++-----     00000############000#12d %2$*1$d!\n",10,15);
  my_printf("%-+++++-----     00000############000#12d %2$*1$d!\n",10,15);
  return (0);
}
