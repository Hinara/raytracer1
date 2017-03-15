/*
** my_getnbr.c for minishell1 in /home/robin.milas/Current/PSU_2016_minishell1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Jan 19 16:10:29 2017 Robin MILAS
** Last update Mon Mar 13 09:56:47 2017 Milas Robin
*/

#include <stdlib.h>

static char	*prepare_negative(char *point, char *neg)
{
  while ((*point >= '0' && *point <= '9') || *point == '+' || *point == '-')
    {
      if (*point == '-')
	{
	  *neg = (*neg + 1) % 2;
	}
      point = point + sizeof(char);
    }
  if (*point != '\0')
    return (NULL);
  return (point);
}

static char	parse_n(char *pointer, char *str, char neg, int *res)
{
  long long int	pow;
  long long int nb;
  long long int validator;

  nb = 0;
  pow = 1;
  validator = -2147483647 - neg;
  while ((*pointer >= '0' && *pointer <= '9') && str <= pointer)
    {
      nb = nb - (*pointer - '0') * pow;
      pow = pow * 10;
      pointer = pointer - sizeof(char);
      if (nb < validator)
	{
	  return (-1);
	}
    }
  if (!neg)
    {
      nb = -nb;
    }
  *res = nb;
  return (0);
}

char		get_nbr(char *str, void *res_v)
{
  int		*tmp;
  int		res;
  char		*pointer;
  char		neg;

  tmp = res_v;
  pointer = str;
  neg = 0;
  pointer = prepare_negative(pointer, &neg);
  if (pointer == NULL || pointer <= str)
  {
    return (-1);
  }
  pointer = pointer - sizeof(char);
  if (parse_n(pointer, str, neg, &res) < 0)
    return (-1);
  *tmp = res;
  return (0);
}
