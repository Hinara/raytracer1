/*
** main.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 13:00:48 2017 Robin MILAS
** Last update Tue Mar  7 21:57:05 2017 Robin MILAS
*/

#include "raytracer.h"

int		main()
{
  t_scene	scene;
  t_coord3d	coord3d;
  t_win		win;

  coord_pos(&coord3d, -30, 0, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (init_scene(&scene, coord3d) < 0)
    return (1);
  scene.light.x = -30.0f;
  scene.light.y = 0.0f;
  scene.light.z = 0.0f;
  coord_pos(&coord3d, 0, 0, -10);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_plane(&scene, coord3d, sfCyan) < 0)
    return (1);
  coord_pos(&coord3d, 0, 0, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfYellow, 3) < 0)
    return (1);
  coord_pos(&coord3d, 0, 0, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_cone(&scene, coord3d, sfRed, 45) < 0)
    return (1);
  win.fb = my_framebuffer_create(1080, 720);
  if (!win.fb.pixels)
    return (my_print("Error creating framebuffer!\n", 1, 84));
  return (window(&scene, &win));
  //raytracer(&scene, &win);
  //return (0);
}
  /*
  coord_pos(&coord3d, 0, 2, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfRed, 3) < 0)
    return (1);
  coord_pos(&coord3d, 0, -2, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfBlue, 3) < 0)
    return (1);
  coord_pos(&coord3d, 0, 4, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfYellow, 3) < 0)
    return (1);
  coord_pos(&coord3d, 0, -4, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfGreen, 3) < 0)
    return (1);
  coord_pos(&coord3d, 0, 6, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfMagenta, 3) < 0)
    return (1);
  */
  /*
  coord_pos(&coord3d, -15, 0, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_plane(&scene, coord3d, sfRed) < 0)
    return (1);
  coord_pos(&coord3d, 0, 7, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfCyan, 3) < 0)
    return (1);
  coord_pos(&coord3d, 0, -9, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfCyan, 3) < 0)
    return (1);

  coord_pos(&coord3d, 0, 0, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_cylinder(&scene, coord3d, sfCyan, 3) < 0)
    return (1);
  coord_pos(&coord3d, 0, 0, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_cone(&scene, coord3d, sfMagenta, 60) < 0)
    return (1);

  coord_pos(&coord3d, 0, 0, 0);
  coord_rot(&coord3d, 0, 0, 0);
  if (add_sphere(&scene, coord3d, sfYellow, 3) < 0)
    return (1);
  */
