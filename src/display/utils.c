/*
** my_error.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 16:14:32 2017 Robin MILAS
** Last update Mon Mar  6 12:44:40 2017 Robin MILAS
*/

#include <unistd.h>

int	my_print(char *str, int fd, int res)
{
  int	index;

  index = 0;
  while (str[index])
    index += 1;
  write(fd, str, index);
  return (res);
}

