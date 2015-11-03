/*
** my_getnbr_base.c for day06 in /home/vuille_f/rendu/Piscine_C_J06/ex_17
** 
** Made by Florian Vuillemot
** Login   <vuille_f@epitech.net>
** 
** Started on  Mon Oct  5 21:14:36 2015 Florian Vuillemot
** Last update Tue Oct  6 09:10:06 2015 Florian Vuillemot
*/

char	*my_revstr(char *str)
{
  char	c;
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  i = i - 1;
  while (i > j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i = i - 1;
      j = j + 1;
    }
  return (str);
}

int	get_size_getnbr_base(char *base)
{
  int	i;

  i = 0;
  while (base[i] && base[i] != '+' && base[i] != '-')
    {
      i = i + 1;
    }
  return (i);
}

int	get_nbr_getnbr_base(char *base, char c, int *power, int size_base)
{
  int	i;

  i = 0;
  while (base[i] && base[i] != c)
    {
      i = i + 1;
    }
  i = i * *power;
  *power = *power * size_base;
  return (i);
}

int	get_signe(char *base)
{
  int	signe;

  signe = 1;
  while (*base)
    {
      if (*base == '-')
	signe = signe * -1;
      base = base + 1;
    }
  return (signe);
}

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	result;
  int	power;
  int	size_base;
  int	signe;
  int	prec;

  size_base = get_size_getnbr_base(base);
  power = 1;
  result = 0;
  signe = get_signe(str);
  my_revstr(str);
  i = 0;
  while (str[i] && str[i] != '+' && str[i] != '-')
    {
      prec = result;
      result = get_nbr_getnbr_base(base, str[i], &power, size_base) * signe + result;
      if (signe > 0 && prec > result)
	return (0);
      else
	if (signe < 0 && prec < result)
	  return (0);
      i = i + 1;
    }
  return (result);
}
