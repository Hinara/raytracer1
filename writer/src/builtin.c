/*
** builtin.c for writer in /home/milasr/Current/raytracer1/writer
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sun Mar 12 17:22:44 2017 Milas Robin
** Last update Mon Mar 13 16:56:08 2017 Milas Robin
*/

#include <fcntl.h>
#include "my.h"

char	help(t_app *app)
{
  (void) app;
  write(1, HELP, my_strlen(HELP));
  write(1, HELP_SC, my_strlen(HELP_SC));
  write(1, HELP_SM, my_strlen(HELP_SM));
  write(1, HELP_AS, my_strlen(HELP_AS));
  write(1, HELP_ACY, my_strlen(HELP_ACY));
  write(1, HELP_ACO, my_strlen(HELP_ACO));
  write(1, HELP_AP, my_strlen(HELP_AP));
  write(1, HELP_R, my_strlen(HELP_R));
  write(1, HELP_H, my_strlen(HELP_H));
  write(1, HELP_P, my_strlen(HELP_P));
  write(1, HELP_W, my_strlen(HELP_W));
  write(1, HELP_Q, my_strlen(HELP_Q));
  return (0);
}

char	scene_create(t_app *app)
{
  if (ask(CAM_POS_X , &(app->scene.cam.pos.x), get_float, 0) ||
      ask(CAM_POS_Y , &(app->scene.cam.pos.y), get_float, 0) ||
      ask(CAM_POS_Z , &(app->scene.cam.pos.z), get_float, 0) ||
      ask(CAM_ROT_X , &(app->scene.cam.rot.x), get_float, 0) ||
      ask(CAM_ROT_Y , &(app->scene.cam.rot.y), get_float, 0) ||
      ask(CAM_ROT_Z , &(app->scene.cam.rot.z), get_float, 0) ||
      ask(LIGHT_X , &(app->scene.light.x), get_float, 0) ||
      ask(LIGHT_Y , &(app->scene.light.y), get_float, 0) ||
      ask(LIGHT_Z , &(app->scene.light.z), get_float, 0) ||
      ask(CAM_SKY , &(app->scene.sky), get_color, 0))
    return (-1);
  app->init = 1;
  app->scene.objs = NULL;
  return (0);
}

char	scene_modify(t_app *app)
{
  if (!(app->init))
    {
      write(1, UNINITIALIZED, my_strlen(UNINITIALIZED));
      return (0);
    }
  if (ask(CAM_POS_X , &(app->scene.cam.pos.x), get_float, 1) ||
      ask(CAM_POS_Y , &(app->scene.cam.pos.y), get_float, 1) ||
      ask(CAM_POS_Z , &(app->scene.cam.pos.z), get_float, 1) ||
      ask(CAM_ROT_X , &(app->scene.cam.rot.x), get_float, 1) ||
      ask(CAM_ROT_Y , &(app->scene.cam.rot.y), get_float, 1) ||
      ask(CAM_ROT_Z , &(app->scene.cam.rot.z), get_float, 1) ||
      ask(CAM_SKY , &(app->scene.sky), get_color, 1))
    return (-1);
  return (0);
}

char	write_file(t_app *app)
{
  int	fd;

  fd = open(app->filepath, O_WRONLY | O_TRUNC | O_CREAT, 0644);
  if (fd < 0)
    {
      write(1, UNABLE_WRITE, my_strlen(UNABLE_WRITE));
    }
  else
    {
      write_struct(fd, app);
    }
  return (0);
}

char	quit(t_app *app)
{
  app->exit = 1;
  return (0);
}
