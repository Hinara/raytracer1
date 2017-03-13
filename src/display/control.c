/*
** rotate.c for wolf3d in /home/robin.milas/Current/wolf3d
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Jan 11 22:11:32 2017 Robin MILAS
** Last update Sat Mar 11 02:48:52 2017 Milas Robin
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
  scene->cam.rot.x += ROTATE_FACTOR * rot_x;
  scene->cam.rot.y += ROTATE_FACTOR * rot_y;
  scene->cam.rot.z += ROTATE_FACTOR * rot_z;
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
  scene->cam.pos.x += move_x;
  scene->cam.pos.y += move_y;
  scene->cam.pos.z += move_z;
  return (move_x || move_y || move_z);
}
