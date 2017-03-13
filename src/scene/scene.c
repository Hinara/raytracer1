/*
** scene.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 13:01:45 2017 Robin MILAS
** Last update Sat Mar 11 18:37:59 2017 Milas Robin
*/

#include <stdlib.h>
#include "raytracer.h"

int	init_scene(t_scene *scene, t_coord3d cam, sfColor sky)
{
  scene->sky = sky;
  scene->cam = cam;
  scene->objs = NULL;
  return (0);
}
