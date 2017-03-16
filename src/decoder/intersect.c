/*
** intersect.c for raytracer in /home/robin.milas/Current/raytracer1/src/decoder
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Sat Feb 25 15:59:57 2017 Robin MILAS
** Last update Thu Mar 16 17:14:59 2017 Milas Robin
*/

#include "raytracer.h"

float	decoder_sphere_intersect(sfVector3f *pos,
				 sfVector3f *dir, t_obj *obj)
{
  float	radius;

  radius = *((float *) (obj->more));
  return (intersect_sphere(*pos, *dir, radius));
}

float	decoder_cone_intersect(sfVector3f *pos,
			       sfVector3f *dir, t_obj *obj)
{
  float	angle;

  angle = *((float *) (obj->more));
  return (intersect_cone(*pos, *dir, angle));
}

float	decoder_cylinder_intersect(sfVector3f *pos,
				   sfVector3f *dir, t_obj *obj)
{
  float	radius;

  radius = *((float *) (obj->more));
  return (intersect_cylinder(*pos, *dir, radius));
}

float	decoder_plane_intersect(sfVector3f *pos,
				sfVector3f *dir, t_obj *obj)
{
  (void) obj;
  return (intersect_plane(*pos, *dir));
}
