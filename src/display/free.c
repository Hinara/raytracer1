/*
** free.c for free in /home/milasr/Current/raytracer1
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Tue Mar 14 14:02:05 2017 Milas Robin
** Last update Sat Mar 18 17:46:44 2017 Milas Robin
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
  sfRenderWindow_destroy(win->window);
  sfSprite_destroy(win->sprite);
  sfTexture_destroy(win->texture);
  free_scene(scene);
}
