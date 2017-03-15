/*
** builtin_remove.c for writer in /home/milasr/Current/raytracer1/writer/src
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Mon Mar 13 10:43:01 2017 Milas Robin
** Last update Tue Mar 14 14:40:32 2017 Milas Robin
*/

#include <stdlib.h>
#include "my.h"

static void	remove_obj2(t_app *app, int pos)
{
  t_obj	*tmp;
  t_obj	**p;

  p = &(app->scene.objs);
  while (pos > 0)
    {
      p = &((*p)->next);
      if (*p == NULL)
	{
	  write(1, INVALID_I, my_strlen(INVALID_I));
	  return ;
	}
      pos -= 1;
    }
  tmp = (*p)->next;
  free(*p);
  *p = tmp;
}

char	remove_obj(t_app *app)
{
  int	pos;

  if (!(app->init))
    {
      write(1, UNINITIALIZED, my_strlen(UNINITIALIZED));
      return (0);
    }
  if (app->scene.objs == NULL)
    {
      write(1, NO_OBJ, my_strlen(NO_OBJ));
      return (0);
    }
  if (ask(REMOVE , &pos, get_nbr, 1))
    return (-1);
  if (pos < 0)
    write(1, UNINITIALIZED, my_strlen(UNINITIALIZED));
  else
    remove_obj2(app, pos);
  return (0);
}
