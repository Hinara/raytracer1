/*
** create_objs.c for writer in /home/milasr/Current/raytracer1/writer/src
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sat Mar 11 17:03:26 2017 Milas Robin
** Last update Sat Mar 11 17:27:59 2017 Milas Robin
*/

char	base(t_app *app, t_obj *obj)
{
  if (ask(BASE_POS_X, &(obj->coord.pos.x), get_float_number) < 0 ||
      ask(BASE_POS_Y, &(obj->coord.pos.y), get_float_number) < 0 ||
      ask(BASE_POS_Z, &(obj->coord.pos.z), get_float_number) < 0 ||
      ask(BASE_ROT_X, &(obj->coord.rot.x), get_float_number) < 0 ||
      ask(BASE_ROT_Y, &(obj->coord.rot.y), get_float_number) < 0 ||
      ask(BASE_ROT_Z, &(obj->coord.rot.z), get_float_number) < 0)
    {
    return (-1);
    }
}

char	ask(char *str, void *res, char (*f)(char *str, void *res))
{
  write(1, str, my_strlen(str));
  line = get_next_line(0);
  if (line == NULL)
    {
      return (-1);
    }
  while (f(line, *res) < 0)
    {
      write(1, INVALID, my_strlen(INVALID));
      write(1, str, my_strlen(str));
      free(line);
      line = get_next_line(0);
      if (line != NULL)
	{
	  return (-1);
	}
    }
  return (0);
}
