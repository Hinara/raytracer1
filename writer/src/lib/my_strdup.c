/*
** my_strdup.c for minishell1 in /home/robin.milas/Current/PSU_2016_minishell1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Jan 19 16:11:19 2017 Robin MILAS
** Last update Thu Jan 19 16:16:33 2017 Robin MILAS
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*strdup;
  int	len;

  len = 0;
  while (src[len])
    len += 1;
  strdup = malloc(sizeof(char) * (len + 1));
  if (!strdup)
      return (NULL);
  strdup[len] = '\0';
  while (len > 0)
    {
      len -= 1;
      strdup[len] = src[len];
    }
  return (strdup);
}
