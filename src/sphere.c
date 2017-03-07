/*
** sphere.c for 104 in /home/robin.milas/Current/104intersection
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Tue Jan  3 14:25:53 2017 Robin MILAS
** Last update Tue Mar  7 22:02:13 2017 Robin MILAS
*/

#include <math.h>
#include <SFML/System.h>
#include "raytracer.h"

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}

float	intersect_sphere(sfVector3f pos, sfVector3f dir, float p)
{
  float	a;
  float	b;
  float	c;

  a = pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2);
  b = 2 * (pos.x * dir.x
	   + pos.y * dir.y
	   + pos.z * dir.z);
  c = pow(pos.x, 2) + pow(pos.y, 2) + pow(pos.z, 2) - pow(p, 2);
  return (intersection(a, b, c));
}
