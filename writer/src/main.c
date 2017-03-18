/*
** main.c for minishell1 in /home/robin.milas/Current/PSU_2016_minishell1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Jan 12 19:30:55 2017 Robin MILAS
** Last update Sat Mar 18 17:50:21 2017 Milas Robin
*/

#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

static const t_cmds	g_cmds[] =
  {
    {"sc", scene_create},
    {"sm", scene_modify},
    {"as", add_sphere},
    {"acy", add_cylinder},
    {"aco", add_cone},
    {"ap", add_plane},
    {"r", remove_obj},
    {"h", help},
    {"p", print_detail},
    {"w", write_file},
    {"q", quit},
    {NULL, quit}
  };

void	find_op(t_app *app, char **table)
{
  int	index;

  index = 0;
  while (g_cmds[index].cmd_name != NULL)
    {
      if (my_strcmp(table[0], g_cmds[index].cmd_name) == 0)
	{
	  if (g_cmds[index].f(app) < 0)
	    app->exit = 1;
	  return ;
	}
      index += 1;
    }
  write(1, UNKNOWN_CMD, my_strlen(UNKNOWN_CMD));
}

int	init(t_app *app, char *filepath)
{
  int	fd;

  app->exit = 0;
  app->init = 0;
  app->filepath = filepath;
  if ((fd = open(filepath, O_RDONLY)) < 0)
    return (my_error(UNREADABLE));
  if (fill_struct(fd, app) < 0)
    return (my_error(INVALID));
  app->init = 1;
  return (0);
}

int	main(int ac, char **av)
{
  char	*line;
  char	**table;
  t_app	app;

  if (ac < 2)
    return (my_error(INVALID_PARAMS));
  if (init(&app, av[1]))
    return (1);
  while (!app.exit)
    {
      write(1, PROMPT, my_strlen(PROMPT));
      if ((line = get_next_line(0)) == NULL)
	break ;
      table = my_str_to_wordtab(line);
      free(line);
      if (table[0] != 0)
	find_op(&app, table);
      free_cmd(table);
    }
  free_scene(&app);
  return (0);
}
