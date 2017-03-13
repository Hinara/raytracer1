/*
** rotate.c for raytracer1 in /home/robin.milas/Current/raytracer1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Feb 20 17:00:31 2017 Robin MILAS
** Last update Mon Mar 13 10:36:49 2017 Milas Robin
*/

#include <math.h>
#include <SFML/System.h>
#include "raytracer.h"

static sfVector3f	rotate_x(sfVector3f *rot, sfVector3f *angle)
{
  sfVector3f	temp;

  temp = *rot;
  rot->y = temp.y * cos(RAD(angle->x)) - temp.z * sin(RAD(angle->x));
  rot->z = temp.y * sin(RAD(angle->x)) + temp.z * cos(RAD(angle->x));
  return (*rot);
}

static sfVector3f	rotate_y(sfVector3f *rot, sfVector3f *angle)
{
  sfVector3f	temp;

  temp = *rot;
  rot->x = temp.x * cos(RAD(angle->y)) + temp.z * sin(RAD(angle->y));
  rot->z = temp.x * -sin(RAD(angle->y)) + temp.z * cos(RAD(angle->y));
  return (*rot);
}

static sfVector3f	rotate_z(sfVector3f *rot, sfVector3f *angle)
{
  sfVector3f	temp;

  temp = *rot;
  rot->x = temp.x * cos(RAD(angle->z)) - temp.y * sin(RAD(angle->z));
  rot->y = temp.x * sin(RAD(angle->z)) + temp.y * cos(RAD(angle->z));
  return (*rot);
}

sfVector3f	rotate_xyz(sfVector3f rot, sfVector3f angle)
{
  rot = rotate_x(&rot, &angle);
  rot = rotate_y(&rot, &angle);
  rot = rotate_z(&rot, &angle);
  return (rot);
}

sfVector3f	rotate_zyx(sfVector3f rot, sfVector3f angle)
{
  rot = rotate_z(&rot, &angle);
  rot = rotate_y(&rot, &angle);
  rot = rotate_x(&rot, &angle);
  return (rot);
}
