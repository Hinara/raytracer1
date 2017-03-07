/*
** normal.c for normal in /home/robin.milas/Current/raytracer1/src/decoder
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Sat Feb 25 16:05:25 2017 Robin MILAS
** Last update Tue Mar  7 21:02:23 2017 Robin MILAS
*/

#include <SFML/System.h>
#include "raytracer.h"

sfVector3f		decoder_sphere_normal(sfVector3f *pos,
				 sfVector3f *dir, t_obj *obj, float k)
{
  sfVector3f	intersect;

  (void) obj;
  intersect.x = pos->x + dir->x * k;
  intersect.y = pos->y + dir->y * k;
  intersect.z = pos->z + dir->z * k;
  return (get_normal_sphere(intersect));
}

sfVector3f	decoder_cone_normal(sfVector3f *pos,
			       sfVector3f *dir, t_obj *obj, float k)
{
  float		angle;
  sfVector3f	intersect;

  (void) obj;
  intersect.x = pos->x + dir->x * k;
  intersect.y = pos->y + dir->y * k;
  intersect.z = pos->z + dir->z * k;
  angle = *((float *) (obj->more));
  return (get_normal_cone(intersect, angle));
}

sfVector3f	decoder_cylinder_normal(sfVector3f *pos,
				   sfVector3f *dir, t_obj *obj, float k)
{
  sfVector3f	intersect;

  (void) obj;
  intersect.x = pos->x + dir->x * k;
  intersect.y = pos->y + dir->y * k;
  intersect.z = pos->z + dir->z * k;
  return (get_normal_cylinder(intersect));

}

sfVector3f	decoder_plane_normal(sfVector3f *pos,
				sfVector3f *dir, t_obj *obj, float k)
{
  (void) dir;
  (void) obj;
  (void) k;
  return (get_normal_plane(pos->z >= 0));
}
