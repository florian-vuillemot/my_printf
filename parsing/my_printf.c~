/*
** test.c for test in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 17:25:12 2015 Florian Vuillemot
** Last update Thu Nov 12 01:54:52 2015 Florian Vuillemot
*/

#include		"pars.h"
#include		"list_va_arg.h"
#include		"get_elem_to_print.h"

void			print_list(t_list_va_arg *arg)
{
  while (arg && arg->cursor)
    {
      printf("index num : %d\n", arg->cursor->index);
      printf("%s\n", get_arg(arg));
    }
}


void			fct(char *str,
			    t_flag *flag, t_string *string, ...)
{
  t_list_va_arg		*arg;
  va_list		list;
  
  va_start(list, string);
  arg = init_list_va_arg(flag, string->string, &list);
  if ((string = get_elem_to_print(string, flag, arg)) == NULL)
    printf("erreur\n");

  //  print_list(arg);
  print_string(string);
  
  free_list_va_arg(arg);
  va_end(list);
}

int			main(int ac, char **av)
{
  t_string		*string;
  t_flag		*flag;
  char			*str; 
  
  flag = init_flag_and_fct();
  str = my_strdup("###00000000 %p 23 ---  %- --##   00%2.* %  5% \n");
  printf(str,"coucou", 100,2,3,3,5,12,32,NULL);
  string = parse(str, flag);
  fct(str, flag, string,"coucou", 100,2,3,3,5,12,32,NULL);
  free_string(string);
  free_flag_and_fct(flag);
  free(str);
  return (0);
}
