/*
** light.c for raytracer.c in /home/robin.milas/Current/raytracer1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Feb 20 17:03:30 2017 Robin MILAS
** Last update Tue Feb 21 11:16:43 2017 Robin MILAS
*/

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  double	factorial;
  double	length1;
  double	length2;

  factorial = (light_vector.x * normal_vector.x
	       + light_vector.y * normal_vector.y
	       + light_vector.z * normal_vector.z);
  length_multiplied = (sqrt(pow(light_vector.x, 2)
			    + pow(light_vector.y, 2)
			    + pow(light_vector.z, 2))
		       * sqrt(pow(normal_vector.x, 2)
			      + pow(normal_vector.y, 2)
			      + pow(normal_vector.z, 2)));
  return (acos(factorial/length_multiplied));
}
