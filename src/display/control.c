/*
** rotate.c for wolf3d in /home/robin.milas/Current/wolf3d
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Jan 11 22:11:32 2017 Robin MILAS
** Last update Wed Mar  8 15:05:41 2017 Robin MILAS
*/

#include "raytracer.h"

char    rotate(t_scene *scene)
{
  char	        rot_x;
  char	        rot_y;
  char	        rot_z;

  rot_x = ((sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) -
	   (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue));
  rot_y = ((sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) -
	   (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue));
  rot_z = ((sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue) -
	   (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue));
  if (rot_x)
    {
      scene->cam.rot.x += ROTATE_FACTOR * rot_x;
    }
  if (rot_y)
    {
      scene->cam.rot.y += ROTATE_FACTOR * rot_y;
    }
  if (rot_z)
    {
      scene->cam.rot.z += ROTATE_FACTOR * rot_z;
    }
  return (rot_x || rot_y || rot_z);
}

char	moves(t_scene *scene)
{
  char	move_x;
  char	move_y;
  char	move_z;

  move_x = ((sfKeyboard_isKeyPressed(sfKeyO) == sfTrue) -
	    (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue));
  move_y = ((sfKeyboard_isKeyPressed(sfKeyK) == sfTrue) -
	    (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue));
  move_z = ((sfKeyboard_isKeyPressed(sfKeyI) == sfTrue) -
	    (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue));
  if (move_x)
    {
      scene->cam.pos.x += move_x;
    }
  if (move_y)
    {
      scene->cam.pos.y += move_y;
    }
  if (move_z)
    {
      scene->cam.pos.z += move_z;
    }
  return (move_x || move_y || move_z);
}
