/*
** translate.c for raytracer1 in /home/robin.milas/Current/raytracer1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Feb 20 16:59:03 2017 Robin MILAS
** Last update Thu Feb 23 11:00:37 2017 Robin MILAS
*/

#include <SFML/System.h>

sfVector3f translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}

sfVector3f rev_translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x -= translations.x;
  to_translate.y -= translations.y;
  to_translate.z -= translations.z;
  return (to_translate);
}
