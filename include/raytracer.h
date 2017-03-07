/*
** raytracer.h for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 11:05:14 2017 Robin MILAS
** Last update Tue Mar  7 22:01:19 2017 Robin MILAS
*/

#ifndef _RAYTRACER_H_
# define _RAYTRACER_H_

# include <math.h>
# include <SFML/Graphics.h>

# define FRAMEBUFFER_WIDTH	800
# define FRAMEBUFFER_HEIGHT	600

# define RAD(x)	((x) * M_PI / 180)

# define SKY	sfBlack

# define DIST	500
# define ROTATE_COEF	0.1

typedef enum	e_shape_type
{
  SPHERE, PLANE, CYLINDER, CONE, UNKNOWN
}		t_shape_type;

/*
** CSFML Structures
*/
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

/*
** Scene structures
*/

typedef struct	s_shape
{
  t_shape_type	shape;
  sfColor	color;
}		t_shape;

typedef struct	s_coord3d
{
  sfVector3f	pos;
  sfVector3f	rot;
}		t_coord3d;

typedef struct	s_obj
{
  t_shape	shape;
  t_coord3d	coord;
  void		*more;
  struct s_obj	*next;
}		t_obj;

typedef struct	s_scene
{
  t_coord3d	cam;
  t_obj		*objs;
  sfVector3f	light;
}		t_scene;

typedef float (*t_intersect)(sfVector3f *pos,
			     sfVector3f *dir, t_obj *obj);

typedef sfVector3f (*t_normal)(sfVector3f *pos,
			       sfVector3f *dir, t_obj *obj, float k) ;

typedef struct	s_obj_dec
{
  t_shape_type	type;
  t_intersect	intersect;
  t_normal	normal;
}		t_obj_dec;
/*
** PROTOTYPE A TRIER
*/
float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);
int			my_print(char *str, int fd, int res);
int			init_scene(t_scene *scene, t_coord3d cam);

void			my_put_pixel(t_my_framebuffer *buf, int x,
				     int y, sfColor color);
int			window(t_scene *scene, t_win *win);
void			raytracer(t_scene *scene, t_win *win);
t_my_framebuffer	my_framebuffer_create(int width, int height);
sfColor			color_brightness(sfColor color, float multiplier);
float			intersection(double a, double b, double c);

/*
** Init structure base structure
*/
void			coord_pos(t_coord3d *base, float x, float y, float z);
void		        coord_rot(t_coord3d *base, float x, float y, float z);

/*
** Add forms
*/
int	add_sphere(t_scene *scene, t_coord3d base,
		   sfColor color, float radius);
int	add_cylinder(t_scene *scene, t_coord3d base,
		     sfColor color, float radius);
int	add_cone(t_scene *scene, t_coord3d base,
		 sfColor color, float angle);
int	add_plane(t_scene *scene, t_coord3d base,
		  sfColor color);

/*
** Transformation
*/
sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i iscreen_size,
				sfVector2i screen_pos);
sfVector3f	translate(sfVector3f to_translate, sfVector3f translations);
sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles);

/*
** Intersect
*/
float		intersect_sphere(sfVector3f eye_pos,
				 sfVector3f dir_vector, float radius);
float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
float		intersect_cylinder(sfVector3f eye_pos,
				   sfVector3f dir_vector, float radius);
float		intersect_cone(sfVector3f eye_pos,
			       sfVector3f dir_vector, float semiangle);

/*
** Normals
*/
sfVector3f	get_normal_sphere(sfVector3f intersection_point);
sfVector3f	get_normal_plane(int upward);
sfVector3f	get_normal_cylinder(sfVector3f intersection_point);
sfVector3f	get_normal_cone(sfVector3f intersection_point,
				float semiangle);

/*
** Decoder
*/
t_intersect	intersect_decoder(t_shape_type type);
t_normal	normal_decoder(t_shape_type type);

float	decoder_sphere_intersect(sfVector3f *pos,
				 sfVector3f *dir, t_obj *obj);
float	decoder_cone_intersect(sfVector3f *pos,
			       sfVector3f *dir, t_obj *obj);
float	decoder_cylinder_intersect(sfVector3f *pos,
				   sfVector3f *dir, t_obj *obj);
float	decoder_plane_intersect(sfVector3f *pos,
				sfVector3f *dir, t_obj *obj);

sfVector3f	decoder_sphere_normal(sfVector3f *pos, sfVector3f *dir,
				      t_obj *obj, float k);
sfVector3f	decoder_cone_normal(sfVector3f *pos, sfVector3f *dir,
				    t_obj *obj, float k);
sfVector3f	decoder_cylinder_normal(sfVector3f *pos, sfVector3f *dir,
					t_obj *obj, float k);
sfVector3f	decoder_plane_normal(sfVector3f *pos, sfVector3f *dir,
				     t_obj *obj, float k);
/*
** Controls
*/
char	moves(t_scene *scene);
char    rotate(t_scene *scene);

#endif
