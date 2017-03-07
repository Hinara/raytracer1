/*
** my_put_pixel.c for Wireframe in /home/robin.milas/
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Nov 17 19:40:51 2016 Robin MILAS
** Last update Wed Feb  8 14:25:49 2017 Robin MILAS
*/

#include "raytracer.h"

void    my_put_pixel(t_my_framebuffer *buf, int x, int y, sfColor color)
{
  int	base;

  if (x >= buf->width || y >= buf->height || x < 0 || y < 0)
    {
      return ;
    }
  base = (x + y * buf->width) * 4;
  buf->pixels[base + 0] = color.r;
  buf->pixels[base + 1] = color.g;
  buf->pixels[base + 2] = color.b;
  buf->pixels[base + 3] = color.a;
}
