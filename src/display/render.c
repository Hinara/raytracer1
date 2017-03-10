/*
** render.c for raytracer.c in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 13:46:33 2017 Robin MILAS
** Last update Fri Mar 10 23:26:10 2017 Milas Robin
*/

#include <math.h>
#include "raytracer.h"

float		find_k(sfVector3f *pos, sfVector3f *dir, t_obj *obj)
{
  sfVector3f	c_pos;
  t_intersect	intersect;

  c_pos = rev_translate(*pos, obj->coord.pos);
  if ((intersect = intersect_decoder(obj->shape.shape)) != NULL)
    return (intersect(&c_pos, dir, obj));
  return (NAN);
}

float		find_cos(t_scene *scene, sfVector3f *dir, t_obj *obj, float k)
{
  sfVector3f	pos;
  sfVector3f    light;
  t_normal	normal;
  sfVector3f	normal_v;
  float		cos;

  pos = rev_translate(scene->cam.pos, obj->coord.pos);
  light = rev_translate(scene->light, vector_move(scene->cam.pos, *dir, k));
  if ((normal = normal_decoder(obj->shape.shape)) != NULL)
    {
      normal_v = normal(&pos, dir, obj, k);
      cos = get_light_coef(light, normal_v);
      if (cos <= 0.0f)
	return (0.0f);
      return (cos);
    }
  return (1.0f);
}

float	        get_closest(t_scene *scene, sfVector3f *pos,
			    sfVector3f *dir, t_obj **closest)
{
  t_obj	*ptr;
  float	k;
  float	temp_k;

  ptr = scene->objs;
  k = INFINITY;
  *closest = NULL;
  while (ptr)
    {
      temp_k = find_k(pos, dir, ptr);
      if (temp_k > 0.0f && temp_k < k)
	{
	  k = temp_k;
	  *closest = ptr;
	}
      ptr = ptr->next;
    }
  return (k);
}

sfColor	get_pixel(t_scene *s, sfVector3f *dir)
{
  sfColor	color;
  sfVector3f	light_v;
  sfVector3f    light_pos;
  sfVector3f    pos;
  t_obj		*obj;
  float		k;

  if ((k = get_closest(s, &(s->cam.pos), dir, &obj)) == INFINITY)
    return (SKY);
  color = obj->shape.color;
  color = color_brightness(color, find_cos(s, dir, obj, k));
  pos = vector_move(s->cam.pos, *dir, k);
  light_v = rev_translate(pos, s->light);
  if ((k = get_closest(s, &(s->light), &light_v, &obj)) < 0.99f)
    {
      color = color_brightness(color, 0.5f);
    }
  return (color);
}

void	raytracer(t_scene *scene, t_win *win)
{
  sfVector2i	pos;
  sfVector2i	window_size;
  sfVector3f	dir;

  window_size.x = win->fb.width;
  window_size.y = win->fb.height;
  pos.x = 0;
  pos.y = 0;
  while (pos.x < window_size.x)
    {
      pos.y = 0;
      while (pos.y < window_size.y)
	{
	  dir = calc_dir_vector(DIST, window_size, pos);
	  dir = rotate_xyz(dir, scene->cam.rot);
	  my_put_pixel(&(win->fb), pos.x, pos.y, get_pixel(scene, &dir));
	  pos.y += 1;
	}
      pos.x += 1;
    }
}
