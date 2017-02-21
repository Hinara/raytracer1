/*
** cylinder.c for 104 in /home/robin.milas/Current/104intersection
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Tue Jan  3 14:34:24 2017 Robin MILAS
** Last update Mon Feb 20 16:53:20 2017 Robin MILAS
*/

#include <math.h>
#include "raytracer.h"

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  intersection_point.z = 0;
  return (intersection_point);
}

static double	intersection(double a, double b, double c)
{
  double	d;
  double	t1;
  double	t2;

  d = pow(b, 2) - (4 * a * c);
  if (d < 0)
    {
      return (NAN);
    }
  else if (d == 0.0)
    {
      return (-b / (2 * a));
    }
  else
    {
      t1 = (-b + sqrt(d)) / (2 * a);
      t2 = (-b - sqrt(d)) / (2 * a);
      if (t1 < t2 && t1 >= 0.0)
	return (t1);
      return (t2);
    }
}

float	intersect_cylinder(sfVector3f pos, sfVector3f dir, int p)
{
  double	a;
  double	b;
  double	c;

  if (dir->x == 0 && dir->y == 0)
    {
      if (pow(pos->x, 2) + pow(pos->y, 2) == p)
	return (0);
      else
	return (NAN);
    }
  a = pow(dir->x, 2) + pow(dir->y, 2);
  b = 2 * ((double) pos->x * dir->x + (double) pos->y * dir->y);
  c = pow(pos->x, 2) + pow(pos->y, 2) - pow(p, 2);
  return (intersection(a, b, c));
}
