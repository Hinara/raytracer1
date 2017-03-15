/*
** my.h for minishell in /home/robin.milas/Current/PSU_2016_minishell1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Jan 12 19:41:48 2017 Robin MILAS
** Last update Tue Mar 14 14:39:01 2017 Milas Robin
*/

#ifndef MINISHELL1_H_
# define MINISHELL1_H_

# include <unistd.h>
# include <SFML/System.h>
# include <SFML/Graphics/Color.h>

# define UNREADABLE	"Unreadable file\n"
# define INVALID	"Invalid content\n"
# define UNKNOWN_CMD	"Command not found try h for help\n"
# define INVALID_PARAMS	"Bad argument\n"
# define INVALID_I	"There is no object with this index\n"

# define MAGIC		"!RAYTRACER"

# define PROMPT "Raytracer>"

# define HELP		"Help:\n"
# define HELP_SC	"\tsc\tCreate scene (Erase all elements)\n"
# define HELP_SM	"\tsm\tModify scene parameters\n"
# define HELP_AS	"\tas\tAdd a sphere to the scene\n"
# define HELP_ACY	"\tacy\tAdd a cylinder to the scene\n"
# define HELP_ACO	"\taco\tAdd a cone to the scene\n"
# define HELP_AP	"\tap\tAdd a plane to the scene\n"
# define HELP_R		"\tr\tRemove an element from the scene\n"
# define HELP_H		"\th\tDisplay this help\n"
# define HELP_P		"\tp\tPrint elements in the scene\n"
# define HELP_W		"\tw\tWrite the new scene\n"
# define HELP_Q		"\tq\tQuit\n"

# define POS_X		"X position of "
# define POS_Y		"Y position of "
# define POS_Z		"Z position of "
# define ROT_X		"X rotation of "
# define ROT_Y		"Y rotation of "
# define ROT_Z		"Z rotation of "

# define OBJ		"the object : "
# define CAM		"the camera : "
# define LIGHT		"the light : "

# define CAM_POS_X	POS_X CAM
# define CAM_POS_Y	POS_Y CAM
# define CAM_POS_Z	POS_Z CAM
# define CAM_ROT_X	ROT_X CAM
# define CAM_ROT_Y	ROT_Y CAM
# define CAM_ROT_Z	ROT_Z CAM

# define CAM_SKY        "The color of the sky (in hexadecimal): "

# define OBJ_POS_X	POS_X OBJ
# define OBJ_POS_Y	POS_Y OBJ
# define OBJ_POS_Z	POS_Z OBJ
# define OBJ_ROT_X	ROT_X OBJ
# define OBJ_ROT_Y	ROT_Y OBJ
# define OBJ_ROT_Z	ROT_Z OBJ

# define LIGHT_X	POS_X LIGHT
# define LIGHT_Y	POS_Y LIGHT
# define LIGHT_Z	POS_Z LIGHT

# define OBJ_COLOR      "The color of the object (in hexadecimal): "
# define RADIUS		"Radius : "
# define SEMI_ANGLE	"Semi-angle : "
# define REMOVE		"Index of the object to remove (<0 to Cancel) : "
# define NO_OBJ		"There is no object to remove."

# define UNINITIALIZED	"Scene not initialized\nPlease use 'sc' before\n"

# define PRINT_SCENE	"Scene :\n"
# define PRINT_CAMERA	"Camera"
# define PRINT_POS	" Pos"
# define PRINT_ROT	" Rot"
# define PRINT_LIGHT	" Light pos"
# define PRINT_SKY	"Sky color : "
# define PRINT_SPHERE	"Sphere"
# define PRINT_CONE	"Cone"
# define PRINT_CYLINDER	"Cylinder"
# define PRINT_PLANE	"Plane"
# define PRINT_COLOR	" Color: "
# define PRINT_COORD_S	"("
# define PRINT_COORD_E	")"
# define PRINT_COORD_SP	","

# define UNABLE_WRITE	"Cannot open the file in write mode\n"
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
  t_obj		*objs;
  sfColor	sky;
  t_coord3d	cam;
  sfVector3f	light;
}		t_scene;

typedef struct	s_app
{
  char		*filepath;
  t_scene	scene;
  char		exit;
  char		init;
}		t_app;

typedef struct	s_cmds
{
  char	        *cmd_name;
  char	        (*f)(t_app *app);
}		t_cmds;

typedef struct	s_objsize
{
  t_shape_type	shape;
  ssize_t	size;
}		t_objsize;

typedef struct	s_names
{
  t_shape_type	shape;
  char		*name;
}		t_names;

/*
** Lib
*/
int	my_strcmp(char *s1, char *s2);
char	**my_str_to_wordtab(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str, int *res);
int	my_error(char *str);
char	*my_strdup(char *src);
char	get_float(char *str, void *res);
char	get_color(char *str, void *res);
char	get_nbr(char *str, void *res);

/*
** Free
*/
void	free_cmd(char **cmd);
int	free_scene(t_app *app);

/*
** Cmds
*/
char	        scene_create(t_app *app);
char	        scene_modify(t_app *app);
char	        add_sphere(t_app *app);
char	        add_cylinder(t_app *app);
char	        add_cone(t_app *app);
char	        add_plane(t_app *app);
char	        remove_obj(t_app *app);
char	        help(t_app *app);
char	        print_detail(t_app *app);
char	        write_file(t_app *app);
char	        quit(t_app *app);

/*
** File management
*/
char	        fill_struct(int fd, t_app *app);
char	        write_struct(int fd, t_app *app);

/*
** Input
*/
char	ask(char *msg, void *res, char (*f)(char *str, void *res),
	    char keep);

/*
** Print functions
*/
void	print_float(float f);
void	print_nb_pos(int nb);

/*
** Utils
*/
ssize_t		my_read(int fd, void *buf, size_t count);

#endif
