/*
** window.c for raytracer in /home/robin.milas/Current/raytracer1/src/display
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Tue Feb 21 11:21:00 2017 Robin MILAS
** Last update Sat Mar 18 17:46:50 2017 Milas Robin
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

#include "raytracer.h"

void		render_window(t_scene *scene, t_win *win)
{
  raytracer(scene, win);
  sfTexture_updateFromPixels(win->texture,
			     win->fb.pixels,
			     win->fb.width,
			     win->fb.height,
			     0, 0);
  sfRenderWindow_drawSprite(win->window,
			    win->sprite, NULL);
  sfRenderWindow_display(win->window);
}

int	        scene_manager(t_scene *scene, t_win *win)
{
  char		modif;

  modif = 0;
  modif |= moves(scene);
  modif |= rotate(scene);
  if (modif)
    render_window(scene, win);
  return (0);
}

sfRenderWindow		*create_window(char* name, int width, int height)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  return (window);
}

int			window(t_scene *scene, t_win *win)
{
  sfEvent		event;
  int			ret;

  if ((win->sprite = sfSprite_create()) == NULL)
    return (my_print("Error creating sprite\n", 1, 84));
  if ((win->texture = sfTexture_create(win->fb.width,
				      win->fb.height)) == NULL)
    return (my_print("Error creating texture\n", 1, 84));
  sfSprite_setTexture(win->sprite, win->texture, sfTrue);
  if ((win->window = create_window("Raytracer1", win->fb.width,
				  win->fb.height)) == NULL)
    return (my_print("Error creating the window\n", 1, 84));
  render_window(scene, win);
  while (sfRenderWindow_isOpen(win->window))
    {
      if (sfRenderWindow_pollEvent(win->window, &event))
	if (event.type == sfEvtClosed)
	  sfRenderWindow_close(win->window);
      ret = scene_manager(scene, win);
      if (ret)
	return (ret);
    }
  free_all(win, scene);
  return (0);
}
