/*
** light.c for raytracer.c in /home/robin.milas/Current/raytracer1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Feb 20 17:03:30 2017 Robin MILAS
** Last update Mon Mar 13 15:21:10 2017 Milas Robin
*/

#include <math.h>
#include <SFML/System.h>

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  double	factorial;
  double	length_multiplied;
  double	res;

  factorial = (light_vector.x * normal_vector.x
	       + light_vector.y * normal_vector.y
	       + light_vector.z * normal_vector.z);
  length_multiplied = (sqrt(powf(light_vector.x, 2)
			    + powf(light_vector.y, 2)
			    + powf(light_vector.z, 2))
		       * sqrt(powf(normal_vector.x, 2)
			      + powf(normal_vector.y, 2)
			      + powf(normal_vector.z, 2)));
  res = factorial / length_multiplied;
  if (!(res >= 0.0))
    res = 0.0;
  return (res);
}
