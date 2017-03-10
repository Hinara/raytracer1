/*
** main.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 13:00:48 2017 Robin MILAS
** Last update Sat Mar 11 00:25:50 2017 Milas Robin
*/

#include "raytracer.h"

int		main()
{
  t_scene	scene;
  t_coord3d	coord3d;
  t_win		win;

  coord3d.pos = vector_create(-70, 40, 25);
  coord3d.rot = vector_create(0, 0, 0);
  if (init_scene(&scene, coord3d) < 0)
    return (1);
  scene.light.x = 0.0f;
  scene.light.y = 100.0f;
  scene.light.z = 32.0f;
  coord3d.pos = vector_create(0, 0, -20);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_plane(&scene, coord3d, sfCyan) < 0)
    return (1);
  coord3d.pos = vector_create(0, 0, 0);
  coord3d.rot = vector_create(0, 0, 0);
  if (add_sphere(&scene, coord3d, sfYellow, 30) < 0)
    return (1);
  coord3d.pos = vector_create(0, -80, 0);
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
  coord3d.pos = vector_create(-50, 40, 0);
  coord3d.rot = vector_create(45, 0, 0);
  if (add_cylinder(&scene, coord3d, sfGreen, 10) < 0)
    return (1);
  win.fb = my_framebuffer_create(1080, 720);
  if (!win.fb.pixels)
    return (my_print("Error creating framebuffer!\n", 1, 84));
  return (window(&scene, &win));
}
