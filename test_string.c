#include "my.h"
#include <stdio.h>
int main()
{
  char		*string;

  string = my_strdup("coucou");
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

  printf("partie 13:\n");
  my_printf("%#-+c<\n", *string);
  printf("%#+-c<\n", *string);
  my_printf("%# -+c<\n", *string);
  printf("%# -+c<\n", *string);

  printf("partie 14:\n");
  my_printf("%#+-*c<\n",10, *string,'l');
  printf("%#+-*c<\n",10, *string);
  my_printf("%*c<\n",10, *string);
  printf("%*c<\n",10, *string);
  my_printf("%#+-*x<\n",10, *string,'l');
  printf("%#+-*x<\n",10, *string);
  my_printf("%*ld<\n",10, *string);
  printf("%*ld<\n",10, *string);
  my_printf("%# -+*.*c %   0000*.*;x %*.*;<\n",10, 20,*string,34,5,64,10,10,"cocuou");
     printf("%# -+*.*c %   0000*.*;x %*.*;<\n",10, 20,*string,34,5,64,10,10,"cocuou");
     printf("%# -+*.*c %   0000*.*;x %2$*1$;d %*.*;<\n",10, 20,*string,34,5,64,10,10,"cocuou");
     printf("rien deb\n");
     my_printf("");
     printf("");
     printf("rien end\n");
     my_printf("%s",NULL);
     printf("%* %%\n",NULL);
     my_printf("%* %%\n",NULL);
     printf("ok %%\n",NULL);
     printf("%*s",NULL);

     free(string);
  return (0);
}
