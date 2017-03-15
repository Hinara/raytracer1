/*
** builtin_print.c for writer in /home/milasr/Current/raytracer1/writer
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Mon Mar 13 10:55:47 2017 Milas Robin
** Last update Mon Mar 13 12:53:34 2017 Milas Robin
*/

#include <stdlib.h>
#include "my.h"

static const t_names	shape_name[]=
  {
    {SPHERE, "Sphere"},
    {CYLINDER, "Cylinder"},
    {CONE, "Cone"},
    {PLANE, "Plane"},
    {UNKNOWN, "?"},
  };

void	print_obj_name(t_shape_type shape)
{
  int	index;

  index = 0;
  while (shape_name[index].shape != UNKNOWN)
    {
      if (shape_name[index].shape == shape)
	{
	  write(1, shape_name[index].name,
		my_strlen(shape_name[index].name));
	  break ;
	}
      index += 1;
    }
  write(1, " ", 1);
}

void	print_color(sfColor color)
{
  char	str[7];
  char	*hexa;

  hexa = "0123456789ABCDEF";
  str[0] = '#';
  str[1] = hexa[color.r / 16];
  str[2] = hexa[color.r % 16];
  str[3] = hexa[color.g / 16];
  str[4] = hexa[color.g % 16];
  str[5] = hexa[color.b / 16];
  str[6] = hexa[color.b % 16];
  write(1, str, 7);
}

void	print_coord(sfVector3f v)
{
  write(1, PRINT_COORD_S, my_strlen(PRINT_COORD_S));
  print_float(v.x);
  write(1, PRINT_COORD_SP, my_strlen(PRINT_COORD_SP));
  print_float(v.y);
  write(1, PRINT_COORD_SP, my_strlen(PRINT_COORD_SP));
  print_float(v.z);
  write(1, PRINT_COORD_E, my_strlen(PRINT_COORD_E));
}

char	print_objs(t_app *app)
{
  t_obj	*obj;
  int	index;

  index = 0;
  obj = app->scene.objs;
  while (obj != NULL)
    {
      write(1, "#", 1);
      print_nb_pos(index);
      write(1, ": ", 2);
      index += 1;
      print_obj_name(obj->shape.shape);
      write(1, PRINT_POS, my_strlen(PRINT_POS));
      print_coord(obj->coord.pos);
      write(1, PRINT_ROT, my_strlen(PRINT_ROT));
      print_coord(obj->coord.rot);
      write(1, PRINT_COLOR, my_strlen(PRINT_COLOR));
      print_color(obj->shape.color);
      write(1, "\n", 1);
      obj = obj->next;
    }
  return (0);
}

char	print_detail(t_app *app)
{
  if (!(app->init))
    {
      write(1, UNINITIALIZED, my_strlen(UNINITIALIZED));
      return (0);
    }
  write(1, PRINT_SCENE, my_strlen(PRINT_SCENE));
  write(1, PRINT_CAMERA, my_strlen(PRINT_CAMERA));
  write(1, PRINT_POS, my_strlen(PRINT_POS));
  print_coord(app->scene.cam.pos);
  write(1, PRINT_ROT, my_strlen(PRINT_ROT));
  print_coord(app->scene.cam.rot);
  write(1, PRINT_LIGHT, my_strlen(PRINT_LIGHT));
  print_coord(app->scene.light);
  write(1, "\n", 1);
  write(1, PRINT_SKY, my_strlen(PRINT_SKY));
  print_color(app->scene.sky);
  write(1, "\n", 1);
  print_objs(app);
  return (0);
}
