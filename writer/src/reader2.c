/*
** reader.c for writer in /home/milasr/Current/raytracer1/writer/src
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sat Mar 11 18:11:50 2017 Milas Robin
** Last update Mon Mar 13 18:02:27 2017 Milas Robin
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

static char	fill_more(int fd, t_obj *obj)
{
  int		index;

  index = 0;
  while (g_objsize[index].shape != UNKNOWN)
    {
      if (g_objsize[index].shape == obj->shape.shape)
	{
	  obj->more = NULL;
	  if (g_objsize[index].size > 0)
	    {
	      obj->more = malloc(g_objsize[index].size);
	      if (obj->more == NULL)
		{
		  obj->next = NULL;
		  return (-1);
		}
	      read(fd, obj->more, g_objsize[index].size);
	    }
	  return (0);
	}
      index += 1;
    }
  obj->next = NULL;
  return (-1);
}

static char	fill_obj_list(int fd, t_app *app)
{
  t_obj		*obj;

  app->scene.objs = malloc(sizeof(*(app->scene.objs)));
  if (app->scene.objs == NULL)
    return (-1);
  obj = app->scene.objs;
  read(fd, obj, sizeof(*obj));
  if (fill_more(fd, obj))
    return (-1);
  while (obj->next != NULL)
    {
      obj->next = malloc(sizeof(*(obj->next)));
      if (obj->next == NULL)
	return (-1);
      obj = obj->next;
      read(fd, obj, sizeof(*obj));
      fill_more(fd, obj);
    }
  return (0);
}

char	fill_struct(int fd, t_app *app)
{
  char	*str;

  str = malloc(my_strlen(MAGIC) + 1);
  if (str == NULL)
    return (-1);
  read(fd, str, my_strlen(MAGIC));
  str[my_strlen(MAGIC)] = '\0';
  if (my_strcmp(str, MAGIC) != 0)
    {
      free(str);
      return (-1);
    }
  free(str);
  read(fd, &(app->scene), sizeof(app->scene));
  if (app->scene.objs != NULL)
    {
      if (fill_obj_list(fd, app))
	{
	  free_scene(app);
	  return (-1);
	}
    }
  return (0);
}
