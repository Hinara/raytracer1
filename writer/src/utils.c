/*
** utils.c for minishell in /home/robin.milas/Current/PSU_2016_minishell1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Sun Jan 15 16:57:11 2017 Robin MILAS
** Last update Tue Mar 14 14:36:40 2017 Milas Robin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_error(char *str)
{
  long	len;

  len = 0;
  while (str[len])
    len += 1;
  write(2, str, len);
  return (84);
}

void	print_nb_pos(int nb)
{
  int	t;

  if (nb > 10)
    print_nb_pos(nb / 10);
  t = nb % 10 + '0';
  write(1, &t , 1);
}

/*
** Read the full specified length if it can
*/
ssize_t		my_read(int fd, void *buf, size_t count)
{
  size_t	len;
  ssize_t	size;

  len = 0;
  size = read(fd, buf, count);
  len += size;
  while (size > 0 && len < count)
    {
      size = read(fd, (char *) buf + len, count - len);
      len += size;
    }
  if (size < 0 ||
      len < count)
    return (-1);
  return (0);
}
