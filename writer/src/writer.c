/*
** reader.c for writer in /home/milasr/Current/raytracer1/writer/src
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sat Mar 11 18:11:50 2017 Milas Robin
** Last update Mon Mar 13 18:02:57 2017 Milas Robin
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static const t_objsize	g_objsize[] =
  {
    {SPHERE, sizeof(float)},
    {PLANE, 0},
    {CYLINDER, sizeof(float)},
    {CONE, sizeof(float)},
    {UNKNOWN, 0}
  };

static char	write_more(int fd, t_obj *obj)
{
  int		index;

  index = 0;
  while (g_objsize[index].shape != UNKNOWN)
    {
      if (g_objsize[index].shape == obj->shape.shape)
	{
	  if (g_objsize[index].size > 0)
	    {
	      write(fd, obj->more, g_objsize[index].size);
	    }
	  return (0);
	}
      index += 1;
    }
  return (-1);
}

static char	write_obj_list(int fd, t_app *app)
{
  t_obj		*objs;

  objs = app->scene.objs;
  write(fd, objs, sizeof(*objs));
  write_more(fd, objs);
  while (objs->next != NULL)
    {
      objs = objs->next;
      write(fd, objs, sizeof(*objs));
      write_more(fd, objs);
    }
  return (0);
}

char	        write_struct(int fd, t_app *app)
{
  write(fd, MAGIC, my_strlen(MAGIC));
  write(fd, &(app->scene), sizeof(app->scene));
  if (app->scene.objs != NULL)
    {
      if (write_obj_list(fd, app))
	{
	  return (-1);
	}
    }
  return (0);
}
