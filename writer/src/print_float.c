/*
** print_float.c for writer in /home/milasr/Current/raytracer1/writer/src
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Mon Mar 13 11:06:28 2017 Milas Robin
** Last update Mon Mar 13 16:46:19 2017 Milas Robin
*/

#include <math.h>
#include "my.h"

void		print_float(float f)
{
  int		nb;
  double	tmp;
  int		after;

  after = (modf(f, &tmp)) * 100;
  nb = tmp;
  if (nb < 0 || after < 0)
    {
      write(1, "-", 1);
      nb = -nb;
      after = -after;
    }
  print_nb_pos(nb);
  if (after > 0)
    {
      write(1, ".", 1);
      print_nb_pos(after);
    }
}
