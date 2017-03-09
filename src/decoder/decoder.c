/*
** decoder.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 15:27:14 2017 Robin MILAS
** Last update Mon Mar  6 12:23:24 2017 Robin MILAS
*/

#include "raytracer.h"

static const t_obj_dec	objtypes[] =
  {
    {SPHERE, decoder_sphere_intersect, decoder_sphere_normal},
    {CONE, decoder_cone_intersect, decoder_cone_normal},
    {CYLINDER, decoder_cylinder_intersect, decoder_cylinder_normal},
    {PLANE, decoder_plane_intersect, decoder_plane_normal},
    {UNKNOWN, decoder_sphere_intersect, decoder_sphere_normal}
  };

t_intersect	intersect_decoder(t_shape_type type)
{
  int		i;

  i = 0;
  while (objtypes[i].type != UNKNOWN)
    {
      if (objtypes[i].type == type)
	return (objtypes[i].intersect);
      i += 1;
    }
  return (NULL);
}

t_normal	normal_decoder(t_shape_type type)
{
  int		i;

  i = 0;
  while (objtypes[i].type != UNKNOWN)
    {
      if (objtypes[i].type == type)
	return (objtypes[i].normal);
      i += 1;
    }
  return (NULL);
}
