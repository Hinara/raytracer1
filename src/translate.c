/*
** translate.c for raytracer1 in /home/robin.milas/Current/raytracer1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Feb 20 16:59:03 2017 Robin MILAS
** Last update Mon Feb 20 17:00:09 2017 Robin MILAS
*/

sfVector3f translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x = translations.x;
  to_translate.y = translations.y;
  to_translate.z = translations.z;
  return (to_translate.z);
}
