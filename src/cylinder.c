/*
** cylinder.c for 104 in /home/robin.milas/Current/104intersection
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Tue Jan  3 14:34:24 2017 Robin MILAS
** Last update Tue Mar  7 22:05:16 2017 Robin MILAS
*/

#include <math.h>
#include <SFML/System.h>
#include "raytracer.h"

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  intersection_point.z = 0;
  return (intersection_point);
}

float	intersect_cylinder(sfVector3f pos, sfVector3f dir, float p)
{
  float	a;
  float	b;
  float	c;

  if (dir.x == 0 && dir.y == 0)
    {
      if (pow(pos.x, 2) + pow(pos.y, 2) == p)
	return (0);
      else
	return (NAN);
    }
  a = pow(dir.x, 2) + pow(dir.y, 2);
  b = 2 * (pos.x * dir.x + pos.y * dir.y);
  c = pow(pos.x, 2) + pow(pos.y, 2) - pow(p, 2);
  return (intersection(a, b, c));
}
