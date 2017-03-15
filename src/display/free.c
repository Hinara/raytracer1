/*
** free.c for free in /home/milasr/Current/raytracer1
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Tue Mar 14 14:02:05 2017 Milas Robin
** Last update Tue Mar 14 16:22:25 2017 Milas Robin
*/

#include <stdlib.h>
#include "raytracer.h"

void	free_scene(t_scene *scene)
{
  t_obj	*obj;
  t_obj	*next;

  obj = scene->objs;
  while (obj != NULL)
    {
      next = obj->next;
      free(obj->more);
      free(obj);
      obj = next;
    }
}

void	free_all(t_win *win, t_scene *scene)
{
  free_scene(scene);
  free(win->texture);
  free(win->sprite);
}
