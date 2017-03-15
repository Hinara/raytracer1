/*
** ask.c for writer in /home/milasr/Current/raytracer1/writer/src
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sat Mar 11 17:29:47 2017 Milas Robin
** Last update Mon Mar 13 12:47:17 2017 Milas Robin
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

char	ask(char *msg, void *res, char (*f)(char *str, void *res),
	    char keep)
{
  char	*line;

  write(1, msg, my_strlen(msg));
  line = get_next_line(0);
  if (line == NULL)
    {
      return (-1);
    }
  while (!(keep && line[0] == '\0') && f(line, res) < 0)
    {
      write(1, INVALID, my_strlen(INVALID));
      write(1, msg, my_strlen(msg));
      free(line);
      line = get_next_line(0);
      if (line == NULL)
	{
	  return (-1);
	}
    }
  free(line);
  return (0);
}
