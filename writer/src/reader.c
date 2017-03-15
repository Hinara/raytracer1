/*
** reader.c for writer in /home/milasr/Current/raytracer1/writer/src
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sat Mar 11 18:11:50 2017 Milas Robin
** Last update Tue Mar 14 14:38:08 2017 Milas Robin
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
	      if (obj->more == NULL ||
		  my_read(fd, obj->more, g_objsize[index].size) < 0)
		{
		  obj->next = NULL;
		  return (-1);
		}
	    }
	  return (0);
	}
      index += 1;
    }
  obj->next = NULL;
  return (-1);
}

static char	fill_obj_list(int fd, t_scene *scene)
{
  t_obj		*obj;

  scene->objs = malloc(sizeof(*(scene->objs)));
  if (scene->objs == NULL)
    return (-1);
  obj = scene->objs;
  if (my_read(fd, obj, sizeof(*obj)) < 0 ||
      fill_more(fd, obj))
    return (-1);
  while (obj->next != NULL)
    {
      obj->next = malloc(sizeof(*(obj->next)));
      if (obj->next == NULL)
	return (-1);
      obj = obj->next;
      if (my_read(fd, obj, sizeof(*obj)) < 0 ||
	  fill_more(fd, obj))
	return (-1);
    }
  return (0);
}

char	fill_struct(int fd, t_app *app)
{
  char	*str;

  str = malloc(my_strlen(MAGIC) + 1);
  if (str == NULL)
    return (-1);
  str[my_strlen(MAGIC)] = '\0';
  if (my_read(fd, str, my_strlen(MAGIC)) < 0 ||
      my_strcmp(str, MAGIC) != 0 ||
      my_read(fd, &(app->scene), sizeof(app->scene)) < 0)
    {
      free(str);
      return (-1);
    }
  free(str);
  if (app->scene.objs != NULL)
    {
      if (fill_obj_list(fd, &(app->scene)))
	{
	  free_scene(app);
	  return (-1);
	}
    }
  return (0);
}
