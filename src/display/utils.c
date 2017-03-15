/*
** my_error.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 16:14:32 2017 Robin MILAS
** Last update Tue Mar 14 16:26:43 2017 Milas Robin
*/

#include <unistd.h>

int	my_print(char *str, int fd, int res)
{
  int	index;

  index = 0;
  while (str[index])
    index += 1;
  if (write(fd, str, index) < 0)
    return (-1);
  return (res);
}

int	my_strlen(char *str)
{
  int	nb;

  nb = 0;
  while (*str != '\0')
    {
      nb = nb + 1;
      str = str + sizeof(char);
    }
  return (nb);
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
