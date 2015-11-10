/*
** test.c for test in /home/vuille_f/PSU_2015_my_printf/parsing
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Sat Nov  7 17:25:12 2015 Florian Vuillemot
** Last update Tue Nov 10 14:47:28 2015 Florian Vuillemot
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
  string = get_elem_to_print(string, flag, arg);

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
  str = my_strdup("###00000000 % 10-d 23 ---  %- --##   00d%2.* %  5d% \n");
  printf(str, 10,2,3,3,5,12,32,NULL);
  string = parse(str, flag);
  fct(str, flag, string, "10","2","3","3","5","12","32");
  free_string(string);
  free_flag_and_fct(flag);
  free(str);
  return (0);
}
