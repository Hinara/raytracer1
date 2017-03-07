/*
** framebuffer.c for bsraytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 10:20:07 2017 Robin MILAS
** Last update Mon Mar  6 12:19:05 2017 Robin MILAS
*/

#include <stdlib.h>
#include "raytracer.h"

t_my_framebuffer	my_framebuffer_create(int w, int h)
{
  t_my_framebuffer	res;
  long			i;

  res.height = h;
  res.width = w;
  while ((res.pixels = malloc(sizeof(*(res.pixels)) * h * w * 4)) == NULL)
    {
      return (res);
    }
  i = 0;
  while (i < h * w)
    {
      res.pixels[i * 4 + 0] = 0;
      res.pixels[i * 4 + 1] = 0;
      res.pixels[i * 4 + 2] = 0;
      res.pixels[i * 4 + 3] = 0;
      i += 1;
    }
  return (res);
}

void    my_framebuffer_destroy(t_my_framebuffer *framebuffer)
{
  free(framebuffer->pixels);
}
