/*
** free.c for minishell1 in /home/robin.milas/Current/PSU_2016_minishell1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Fri Jan 20 11:28:40 2017 Robin MILAS
** Last update Mon Mar 13 17:24:02 2017 Milas Robin
*/

#include <stdlib.h>
#include "my.h"

void	free_cmd(char **cmd)
{
  int	i;

  i = 0;
  while (cmd[i])
    {
      free(cmd[i]);
      i += 1;
    }
  free(cmd);
}

int	free_scene(t_app *app)
{
  t_obj	*p;
  t_obj	*next;

  if (app->init)
    {
      p = app->scene.objs;
      app->scene.objs = NULL;
      while (p != NULL)
	{
	  next = p->next;
	  free(p->more);
	  free(p);
	  p = next;
	}
    }
  return (0);
}
