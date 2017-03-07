/*
** coord3d.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 13:36:23 2017 Robin MILAS
** Last update Sat Feb 25 16:21:58 2017 Robin MILAS
*/

#include "raytracer.h"

void  coord_pos(t_coord3d *base, float x, float y, float z)
{
  base->pos.x = x;
  base->pos.y = y;
  base->pos.z = z;
}

void  coord_rot(t_coord3d *base, float x, float y, float z)
{
  base->rot.x = x;
  base->rot.y = y;
  base->rot.z = z;
}
