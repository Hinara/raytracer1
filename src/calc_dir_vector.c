/*
** calc_dir_vector.c for bsraytracer1 in ~/Current/bsraytracer1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Feb  6 14:25:17 2017 Robin MILAS
** Last update Mon Mar  6 13:19:41 2017 Robin MILAS
*/

#include <SFML/System.h>

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i scr_size,
				sfVector2i scr_pos)
{
  sfVector3f	dir;

  dir.x = dist_to_plane;
  dir.y = (((float) scr_size.x) / 2) - scr_pos.x;
  dir.z = (((float) scr_size.y) / 2) - scr_pos.y;
  return (dir);
}
