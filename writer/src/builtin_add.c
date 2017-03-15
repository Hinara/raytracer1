/*
** builtin_add.c for writer in /home/milasr/Current/raytracer1/writer
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sun Mar 12 19:19:20 2017 Milas Robin
** Last update Mon Mar 13 17:10:43 2017 Milas Robin
*/

#include <stdlib.h>
#include "my.h"

static void	insert(t_app *app, t_obj *add)
{
  t_obj	*obj;

  if (app->scene.objs == NULL)
    app->scene.objs = add;
  else
    {
      obj = app->scene.objs;
      while (obj->next != NULL)
	obj = obj->next;
      obj->next = add;
    }
}

char	add_sphere(t_app *app)
{
  t_obj	*obj;
  if (!(app->init))
    {
      write(1, UNINITIALIZED, my_strlen(UNINITIALIZED));
      return (0);
    }
  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (-1);
  obj->next = NULL;
  insert(app, obj);
  if ((obj->more = malloc(sizeof(float))) == NULL)
    return (-1);
  obj->shape.shape = SPHERE;
  if (ask(OBJ_POS_X , &(obj->coord.pos.x), get_float, 0) ||
      ask(OBJ_POS_Y , &(obj->coord.pos.y), get_float, 0) ||
      ask(OBJ_POS_Z , &(obj->coord.pos.z), get_float, 0) ||
      ask(OBJ_ROT_X , &(obj->coord.rot.x), get_float, 0) ||
      ask(OBJ_ROT_Y , &(obj->coord.rot.y), get_float, 0) ||
      ask(OBJ_ROT_Z , &(obj->coord.rot.z), get_float, 0) ||
      ask(OBJ_COLOR , &(obj->shape.color), get_color, 0) ||
      ask(RADIUS , obj->more, get_float, 0))
    return (-1);
  return (0);
}

char	add_cylinder(t_app *app)
{
  t_obj	*obj;
  if (!(app->init))
    {
      write(1, UNINITIALIZED, my_strlen(UNINITIALIZED));
      return (0);
    }
  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (-1);
  obj->next = NULL;
  insert(app, obj);
  if ((obj->more = malloc(sizeof(float))) == NULL)
    return (-1);
  obj->shape.shape = CYLINDER;
  if (ask(OBJ_POS_X , &(obj->coord.pos.x), get_float, 0) ||
      ask(OBJ_POS_Y , &(obj->coord.pos.y), get_float, 0) ||
      ask(OBJ_POS_Z , &(obj->coord.pos.z), get_float, 0) ||
      ask(OBJ_ROT_X , &(obj->coord.rot.x), get_float, 0) ||
      ask(OBJ_ROT_Y , &(obj->coord.rot.y), get_float, 0) ||
      ask(OBJ_ROT_Z , &(obj->coord.rot.z), get_float, 0) ||
      ask(OBJ_COLOR , &(obj->shape.color), get_color, 0) ||
      ask(RADIUS , obj->more, get_float, 0))
    return (-1);
  return (0);
}

char	add_cone(t_app *app)
{
  t_obj	*obj;
  if (!(app->init))
    {
      write(1, UNINITIALIZED, my_strlen(UNINITIALIZED));
      return (0);
    }
  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (-1);
  obj->next = NULL;
  insert(app, obj);
  if ((obj->more = malloc(sizeof(float))) == NULL)
    return (-1);
  obj->shape.shape = CONE;
  if (ask(OBJ_POS_X , &(obj->coord.pos.x), get_float, 0) ||
      ask(OBJ_POS_Y , &(obj->coord.pos.y), get_float, 0) ||
      ask(OBJ_POS_Z , &(obj->coord.pos.z), get_float, 0) ||
      ask(OBJ_ROT_X , &(obj->coord.rot.x), get_float, 0) ||
      ask(OBJ_ROT_Y , &(obj->coord.rot.y), get_float, 0) ||
      ask(OBJ_ROT_Z , &(obj->coord.rot.z), get_float, 0) ||
      ask(OBJ_COLOR , &(obj->shape.color), get_color, 0) ||
      ask(SEMI_ANGLE , obj->more, get_float, 0))
    return (-1);
  return (0);
}

char	add_plane(t_app *app)
{
  t_obj	*obj;
  if (!(app->init))
    {
      write(1, UNINITIALIZED, my_strlen(UNINITIALIZED));
      return (0);
    }
  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (-1);
  obj->next = NULL;
  insert(app, obj);
  obj->shape.shape = PLANE;
  obj->more = NULL;
  if (ask(OBJ_POS_X , &(obj->coord.pos.x), get_float, 0) ||
      ask(OBJ_POS_Y , &(obj->coord.pos.y), get_float, 0) ||
      ask(OBJ_POS_Z , &(obj->coord.pos.z), get_float, 0) ||
      ask(OBJ_ROT_X , &(obj->coord.rot.x), get_float, 0) ||
      ask(OBJ_ROT_Y , &(obj->coord.rot.y), get_float, 0) ||
      ask(OBJ_ROT_Z , &(obj->coord.rot.z), get_float, 0) ||
      ask(OBJ_COLOR , &(obj->shape.color), get_color, 0))
    return (-1);
  return (0);
}
