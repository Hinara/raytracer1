/*
** get_color.c for writer in /home/milasr/Current/raytracer1/writer
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sun Mar 12 18:08:47 2017 Milas Robin
** Last update Mon Mar 13 10:05:37 2017 Milas Robin
*/

#include "my.h"

static inline int	get_hexadecimal(char c)
{
  char			*str;
  int			index;

  str = "0123456789ABCDEF";
  if (c >= 'a' && c <= 'f')
    c += 'A' - 'a';
  index = 0;
  while (str[index])
    {
      if (str[index] == c)
	{
	  return (index);
	}
      index += 1;
    }
  return (-1);
}

char	loop(char *str, sfColor *res)
{
  int	index;
  char	temp;

  index = 0;
  while (str[index] != '\0')
    {
      if (index > 5 || (temp = get_hexadecimal(str[index])) < 0)
	return (-1);
      if (index  < 2)
	res->r = res->r * 16 + temp;
      else if (index < 4)
	res->g = res->g * 16 + temp;
      else
	res->b = res->b * 16 + temp;
      index += 1;
    }
  if (index != 6)
    return (-1);
  return (0);
}

char		get_color(char *str, void *res_v)
{
  sfColor	*tmp;
  sfColor	res;

  tmp = res_v;
  res = sfBlack;
  if (*str == '#')
    str += 1;
  if (loop(str, &res) < 0)
    return (-1);
  *tmp = res;
  return (0);
}
