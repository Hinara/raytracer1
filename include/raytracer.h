/*
** raytracer.h for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 11:05:14 2017 Robin MILAS
** Last update Tue Feb 21 13:26:23 2017 Robin MILAS
*/

#ifndef _RAYTRACER_H_
# define _RAYTRACER_H_

# include <math.h>
# include <SFML/Graphics.h>

# define	FRAMEBUFFER_WIDTH	800
# define	FRAMEBUFFER_HEIGHT	600

# define	RAD(x)	((x) * M_PI / 180)

/*
** Define obj_type
*/
# define	SPHERE		0
# define	PLANE		1
# define	CYLINDER	2
# define	CONE		3

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct		s_win
{
  t_my_framebuffer	fb;
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_win;

typedef struct	s_coord3d
{
  sfVector3f	pos;
  sfVector3f	rot;
}		t_coord3d;

typedef struct	s_obj
{
  int		obj_type;
  t_coord3d      coord;
  sfColor	color;
  void		*more;
  struct s_obj	*next;
}		t_obj;

typedef struct	s_scene
{
  t_coord3d	cam;
  t_obj		*objs;
}		t_scene;

typedef struct	s_objtype
{
  int		type;
  double	(*f)(sfVector3f *pos, sfVector3f *dir, t_obj *obj);
}		t_objtype;

int			add_sphere(t_scene *scene, t_coord3d base,
				   sfColor color, float radius);
int			add_cylinder(t_scene *scene, t_coord3d base,
				     sfColor color, float radius);
int			add_cone(t_scene *scene, t_coord3d base,
				 sfColor color, float angle);
int			add_plane(t_scene *scene, t_coord3d base,
				  sfColor color, int type);

int			init_scene(t_scene *scene, t_base3d cam);
void			base_pos(t_coord3d *base, float x, float y, float z);
void			base_rot(t_coord3d *base, float x, float y, float z);
sfVector3f		calc_dir_vector(sfVector2i scr_size, sfVector2i scr_pos);
void			my_put_pixel(t_my_framebuffer *buf, int x,
				     int y, sfColor color);
int			window(t_scene *scene, t_win *win);
int			my_error(char *str);
double			intersection(double a, double b, double c);
void			raytracer(t_scene *scene, t_win *win);
t_my_framebuffer	my_framebuffer_create(int width, int height);

/*
** Surfaces
*/
double  sphere(sfVector3f *pos, sfVector3f *dir, int p);
double	cylinder(sfVector3f *pos, sfVector3f *dir, int p);
double  cone(sfVector3f *pos, sfVector3f *dir, int p);
double  plane(sfVector3f *pos, sfVector3f *dir, int type);

/*
** Decoder
*/
double	decoder_sphere(sfVector3f *pos, sfVector3f *dir, t_obj *obj);
double	decoder_cylinder(sfVector3f *pos, sfVector3f *dir, t_obj *obj);
double	decoder_cone(sfVector3f *pos, sfVector3f *dir, t_obj *obj);
double	decoder_plane(sfVector3f *pos, sfVector3f *dir, t_obj *obj);

char    rotate(t_scene *scene);

#endif
