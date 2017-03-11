/*
** add_objs.c for raytracer in /home/robin.milas/Current/raytracer1/src/display
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Tue Feb 21 13:38:46 2017 Robin MILAS
** Last update Sat Mar 11 04:08:40 2017 Milas Robin
*/

#include <stdlib.h>
#include <SFML/System.h>
#include "raytracer.h"

static int	add_obj(t_scene *scene, t_coord3d coord,
			t_shape shape, void *more)
{
  t_obj		**ptr;
  t_obj		*obj;

  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (-1);
  obj->coord = coord;
  obj->shape = shape;
  obj->more = more;
  obj->next = NULL;
  ptr = &(scene->objs);
  while (*ptr)
    ptr = &((*ptr)->next);
  *ptr = obj;
  return (0);
}

int	add_sphere(t_scene *scene, t_coord3d base, sfColor color, float radius)
{
  float		*r;
  t_shape	shape;

  if ((r = malloc(sizeof(*r))) == NULL)
    return (-1);
  *r = radius;
  shape.shape = SPHERE;
  shape.color = color;
  return (add_obj(scene, base, shape, r));
}

int	add_cylinder(t_scene *scene, t_coord3d base,
		     sfColor color, float radius)
{
  float		*r;
  t_shape	shape;

  if ((r = malloc(sizeof(*r))) == NULL)
    return (-1);
  *r = radius;
  shape.shape = CYLINDER;
  shape.color = color;
  return (add_obj(scene, base, shape, r));
}

int	add_cone(t_scene *scene, t_coord3d base, sfColor color, float angle)
{
  float		*a;
  t_shape	shape;

  if ((a = malloc(sizeof(*a))) == NULL)
    return (-1);
  *a = angle;
  shape.shape = CONE;
  shape.color = color;
  return (add_obj(scene, base, shape, a));
}

int	add_plane(t_scene *scene, t_coord3d base, sfColor color)
{
  t_shape	shape;

  shape.shape = PLANE;
  shape.color = color;
  return (add_obj(scene, base, shape, NULL));
}
