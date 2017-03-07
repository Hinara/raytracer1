/*
** scene.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 13:01:45 2017 Robin MILAS
** Last update Sat Feb 25 15:50:57 2017 Robin MILAS
*/

#include <stdlib.h>
#include "raytracer.h"

int	init_scene(t_scene *scene, t_coord3d cam)
{
  scene->cam = cam;
  scene->objs = NULL;
  return (0);
}
