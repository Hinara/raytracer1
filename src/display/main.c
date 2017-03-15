/*
** main.c for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 13:00:48 2017 Robin MILAS
** Last update Wed Mar 15 11:37:16 2017 Milas Robin
*/

#include <unistd.h>
#include <fcntl.h>
#include "raytracer.h"

int		main(int ac, char **av)
{
  t_scene	scene;
  t_win		win;
  int		fd;

  if (ac < 2)
    {
      return (my_print("Need a file to work\n", 2, 0));
    }
  if ((fd = open(av[1], O_RDONLY)) < 0)
    {
      return (my_print(UNREADABLE, 2, 1));
    }
  if (fill_struct(fd, &scene) < 0)
    {
      return (my_print(INVALID, 2, 1));
    }
  close(fd);
  win.fb = my_framebuffer_create(800, 600);
  if (!win.fb.pixels)
    return (my_print("Error creating framebuffer!\n", 1, 84));
  return (window(&scene, &win));
}
