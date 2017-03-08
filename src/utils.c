/*
** utils.c for raytracer in /home/robin.milas/Current/raytracer1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Tue Mar  7 21:58:14 2017 Robin MILAS
** Last update Tue Mar  7 22:13:41 2017 Robin MILAS
*/

#include <math.h>

float	intersection(double a, double b, double c)
{
  double	d;
  double	t1;
  double	t2;

  d = pow(b, 2) - (4 * a * c);
  if (d < 0)
    {
      return (-1);
    }
  else if (d == 0.0)
    {
      return (-b / (2 * a));
    }
  else
    {
      t1 = (-b + sqrt(d)) / (2 * a);
      t2 = (-b - sqrt(d)) / (2 * a);
      if (t1 < t2 || t2 <= 0.0f)
	return (t1);
      return (t2);
    }
}
