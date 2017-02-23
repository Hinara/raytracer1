/*
** rotate.c for raytracer1 in /home/robin.milas/Current/raytracer1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Feb 20 17:00:31 2017 Robin MILAS
** Last update Thu Feb 23 11:08:02 2017 Robin MILAS
*/

#include <math.h>
#include <SFML/System.h>

sfVector3f	rotate_xyz(sfVector3f rot, sfVector3f angle)
{
  sfVector3f	temp;

  if (rot.x)
    {
      temp = rot;
      rot.y = temp.y * cos(angle.x) - temp.z * sin(angle.x);
      rot.z = temp.y * sin(angle.x) + temp.z * cos(angle.x);
    }
  if (rot.y)
    {
      temp = rot;
      rot.x = temp.x * cos(angle.y) + temp.z * sin(angle.y);
      rot.z = temp.x * -sin(angle.y) + temp.z * cos(angle.y);
    }
  if (rot.z)
    {
      temp = rot;
      rot.x = temp.x * cos(angle.z) - temp.y * sin(angle.z);
      rot.y = temp.x * sin(angle.z) + temp.y * cos(angle.z);
    }
  return (rot);
}

sfVector3f	rotate_zyx(sfVector3f rot, sfVector3f angle)
{
  sfVector3f	temp;

  if (rot.z)
    {
      temp = rot;
      rot.x = temp.x * cos(angle.z) - temp.y * sin(angle.z);
      rot.y = temp.x * sin(angle.z) + temp.y * cos(angle.z);
    }
  if (rot.y)
    {
      temp = rot;
      rot.x = temp.x * cos(angle.y) + temp.z * sin(angle.y);
      rot.z = temp.x * -sin(angle.y) + temp.z * cos(angle.y);
    }
  if (rot.x)
    {
      temp = rot;
      rot.y = temp.y * cos(angle.x) - temp.z * sin(angle.x);
      rot.z = temp.y * sin(angle.x) + temp.z * cos(angle.x);
    }
  return (rot);
}
