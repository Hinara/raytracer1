/*
** color.c for raytracer.c in /home/robin.milas/Current/raytracer1/src/display
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Tue Feb 21 11:23:29 2017 Robin MILAS
** Last update Tue Mar  7 20:59:02 2017 Robin MILAS
*/

#include <SFML/System.h>
#include "raytracer.h"

sfColor		color_brightness(sfColor color, float multiplier)
{
  sfColor	temp;

  if (!(multiplier < 1))
    return (color);
  temp.a = color.a;
  temp.r = color.r * multiplier;
  temp.g = color.g * multiplier;
  temp.b = color.b * multiplier;
  return (temp);
}

sfColor		color_brightness_more(sfColor color,
				      float multiplier, sfColor light)
{
  sfColor	temp;

  if (!(multiplier < 1))
    multiplier = 1;
  temp.a = color.a;
  temp.r = color.r * multiplier * (light.r / 255.0f);
  temp.g = color.g * multiplier * (light.g / 255.0f);
  temp.b = color.b * multiplier * (light.b / 255.0f);
  return (temp);
}
