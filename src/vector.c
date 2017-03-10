/*
** vector.c for raytracer in /home/milasr/Current/raytracer1
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Thu Mar  9 14:37:37 2017 Milas Robin
** Last update Sat Mar 11 00:09:12 2017 Milas Robin
*/

#include <SFML/System.h>
#include "raytracer.h"

sfVector3f	vector_move(sfVector3f org, sfVector3f dir, float k)
{
  return (translate(org, vector_multiply(dir, k)));
}

sfVector3f	vector_create(float x, float y, float z)
{
  sfVector3f vec;

  vec.x = x;
  vec.y = y;
  vec.z = z;
  return (vec);
}

sfVector3f	vector_multiply(sfVector3f vec, float k)
{
  vec.x *= k;
  vec.y *= k;
  vec.z *= k;
  return (vec);
}

sfVector3f	vector_reverse(sfVector3f vec)
{
  vec.x = -vec.x;
  vec.y = -vec.y;
  vec.z = -vec.z;
  return (vec);
}
