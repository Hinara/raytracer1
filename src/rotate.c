/*
** rotate.c for raytracer1 in /home/robin.milas/Current/raytracer1/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Feb 20 17:00:31 2017 Robin MILAS
** Last update Tue Feb 21 11:14:34 2017 Robin MILAS
*/

sfVector3f	rotate_xyz(sfVector3f rot, sfVector3f angle)
{
  sfVector3f	temp;

  if (rot.x)
    {
      temp = dir;
      dir.y = temp.y * cos(rot.x) - temp.z * sin(rot.x);
      dir.z = temp.y * sin(rot.x) + temp.z * cos(rot.x);
    }
  if (rot.y)
    {
      temp = dir;
      dir.x = temp.x * cos(rot.y) + temp.z * sin(rot.y);
      dir.z = temp.x * -sin(rot.y) + temp.z * cos(rot.y);
    }
  if (rot.z)
    {
      temp = dir;
      dir.x = temp.x * cos(rot.z) - temp.y * sin(rot.z);
      dir.y = temp.x * sin(rot.z) + temp.y * cos(rot.z);
    }
  return (dir);
}

sfVector3f	rotate_zyx(sfVector3f rot, sfVector3f angle)
{
  sfVector3f	temp;

  if (rot.z)
    {
      temp = dir;
      dir.x = temp.x * cos(rot.z) - temp.y * sin(rot.z);
      dir.y = temp.x * sin(rot.z) + temp.y * cos(rot.z);
    }
  if (rot.y)
    {
      temp = dir;
      dir.x = temp.x * cos(rot.y) + temp.z * sin(rot.y);
      dir.z = temp.x * -sin(rot.y) + temp.z * cos(rot.y);
    }
  if (rot.x)
    {
      temp = dir;
      dir.y = temp.y * cos(rot.x) - temp.z * sin(rot.x);
      dir.z = temp.y * sin(rot.x) + temp.z * cos(rot.x);
    }
  return (dir);
}
