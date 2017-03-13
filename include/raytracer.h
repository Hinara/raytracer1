/*
** raytracer.h for raytracer1 in /home/robin.milas/Current/bsraytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Feb  8 11:05:14 2017 Robin MILAS
** Last update Sat Mar 11 18:39:28 2017 Milas Robin
*/

#ifndef _RAYTRACER_H_
# define _RAYTRACER_H_

/*
** Necessary include for prototypes
*/
# include <SFML/Graphics.h>

/*
** Framebuffer dimensions
*/
# define FRAMEBUFFER_WIDTH	800
# define FRAMEBUFFER_HEIGHT	600

/*
** Small define to convert degrees in radius
*/
# define RAD(x)	((x) * M_PI / 180)

/*
** Default color when there no collide beetween a ray and all objects
*/
# define SKY	sfBlack

/*
** Distance beetween the center camera point and the screen plane
*/
# define DIST			500

/*
** Rotation factor when a player rotate the camera
*/
# define ROTATE_FACTOR		10

/*
** A enum of all the available shapes
*/
typedef enum	e_shape_type
{
  SPHERE,
  PLANE,
  CYLINDER,
  CONE,
  UNKNOWN
}		t_shape_type;

/*
** Framebuffer structure
*/
typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}
  t_my_framebuffer;

/*
** CSFML Data structure
*/
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

/*
** Contain the shape and the color of the object
*/
typedef struct	s_shape
{
  t_shape_type	shape;
  sfColor	color;
}		t_shape;

/*
** Contains the position and the rotation of the object
*/
typedef struct	s_coord3d
{
  sfVector3f	pos;
  sfVector3f	rot;
}		t_coord3d;

/*
** The object structure
** More can be used to stock information specific to the shape
*/
typedef struct	s_obj
{
  t_shape	shape;
  t_coord3d	coord;
  void		*more;
  struct s_obj	*next;
}		t_obj;

/*
** The scene structure
** Contain the camera coordinates
** The light position
** The first object of the chained list
*/
typedef struct	s_scene
{
  sfColor	sky;
  t_coord3d	cam;
  t_obj		*objs;
  sfVector3f	light;
}		t_scene;

/*
** Define a type for intersections decoders
*/
typedef float (*t_intersect)(sfVector3f *pos,
			     sfVector3f *dir, t_obj *obj);

/*
** Define a type for normals decoders
*/
typedef sfVector3f (*t_normal)(sfVector3f *pos,
			       sfVector3f *dir, t_obj *obj, float k) ;

/*
** Use to make an array of pointer with shape type as index
*/
typedef struct	s_obj_dec
{
  t_shape_type	type;
  t_intersect	intersect;
  t_normal	normal;
}		t_obj_dec;

/*
** Translations
*/
sfVector3f	translate(sfVector3f to_translate, sfVector3f translations);
sfVector3f	rev_translate(sfVector3f to_translate,
			      sfVector3f translations);
/*
** Rotations
*/
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

/*
** Intersect decoder
*/
float	decoder_sphere_intersect(sfVector3f *pos,
				 sfVector3f *dir, t_obj *obj);
float	decoder_cone_intersect(sfVector3f *pos,
			       sfVector3f *dir, t_obj *obj);
float	decoder_cylinder_intersect(sfVector3f *pos,
				   sfVector3f *dir, t_obj *obj);
float	decoder_plane_intersect(sfVector3f *pos,
				sfVector3f *dir, t_obj *obj);

/*
** Normal decoder
*/
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

/*
** Manage light
*/
float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);

/*
** Vectors operations
*/
sfVector3f	vector_move(sfVector3f org, sfVector3f dir, float k);
sfVector3f	vector_create(float x, float y, float z);
sfVector3f	vector_multiply(sfVector3f vec, float k);
sfVector3f	vector_reverse(sfVector3f vec);

/*
** Add object functions
*/
int	add_sphere(t_scene *scene, t_coord3d base, sfColor color, float radius);
int	add_cylinder(t_scene *scene, t_coord3d base,
		     sfColor color, float radius);
int	add_cone(t_scene *scene, t_coord3d base, sfColor color, float angle);
int	add_plane(t_scene *scene, t_coord3d base, sfColor color);

/*
** Scene function
*/
int	init_scene(t_scene *scene, t_coord3d cam, sfColor sky);

/*
** Math util function
*/
float                  intersection(double a, double b, double c);

/*
** Light function
*/
float  get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);

/*
** Util functions
*/
int                    my_print(char *str, int fd, int res);

/*
** Display functions
*/
void                   my_put_pixel(t_my_framebuffer *buf, int x, int y,
				    sfColor color);
int                    window(t_scene *scene, t_win *win);
void                   raytracer(t_scene *scene, t_win *win);
t_my_framebuffer       my_framebuffer_create(int width, int height);

/*
** Color operations
*/
sfColor			color_brightness(sfColor color, float multiplier);

/*
** Calc vector director function
*/
sfVector3f     calc_dir_vector(float dist_to_plane,
			       sfVector2i iscreen_size,
			       sfVector2i screen_pos);

#endif
