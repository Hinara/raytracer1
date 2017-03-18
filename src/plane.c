/*
** sphere.c for 104 in /home/robin.milas/Current/104intersection
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Tue Jan  3 14:25:53 2017 Robin MILAS
** Last update Sat Mar 18 17:36:11 2017 Milas Robin
*/

#include <math.h>
#include <SFML/System.h>

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	res;

  res.x = 0;
  res.y = 0;
  res.z = (upward) ? 100 : -100;
  return (res);
}

float	intersect_plane(sfVector3f pos, sfVector3f dir)
{
  if (dir.z == 0.0)
    return (-1.0f);
  return (-(pos.z / dir.z));
}
