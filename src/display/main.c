/*
** main.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 13:00:48 2017 Robin MILAS
** Last update Thu Mar  9 16:45:56 2017 Milas Robin
*/

#include "raytracer.h"

int		main()
{
  t_scene	scene;
  t_coord3d	coord3d;
  t_win		win;

  coord3d.pos = vector_create(-50, 0, 25);
  coord3d.rot = vector_create(0, 0, 0);
  if (init_scene(&scene, coord3d) < 0)
    return (1);
  scene.light.x = -50.0f;
  scene.light.y = 0.0f;
  scene.light.z = -9.0f;
  coord3d.pos = vector_create(0, 0, -10);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_plane(&scene, coord3d, sfCyan) < 0)
    return (1);
  coord3d.pos = vector_create(0, 0, 0);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_sphere(&scene, coord3d, sfYellow, 30) < 0)
    return (1);
  coord3d.pos = vector_create(0, 0, 0);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_cone(&scene, coord3d, sfWhite, 45) < 0)
    return (1);
  coord3d.pos = vector_create(0, 10, 0);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_sphere(&scene, coord3d, sfRed, 30) < 0)
    return (1);
  coord3d.pos = vector_create(0, -10, 0);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_sphere(&scene, coord3d, sfBlue, 30) < 0)
    return (1);
  coord3d.pos = vector_create(0, 30, 0);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_sphere(&scene, coord3d, sfMagenta, 30) < 0)
    return (1);
  win.fb = my_framebuffer_create(1080, 720);
  coord3d.pos = vector_create(-50, 40, 0);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_cylinder(&scene, coord3d, sfGreen, 10) < 0)
    return (1);
  if (!win.fb.pixels)
    return (my_print("Error creating framebuffer!\n", 1, 84));
  return (window(&scene, &win));
  //raytracer(&scene, &win);
  //return (0);
}
