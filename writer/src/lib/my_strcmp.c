/*
** my_strcmp.c for minishell1 in /home/robin.milas/Current/PSU_2016_minishell1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Jan 19 16:10:46 2017 Robin MILAS
** Last update Thu Jan 19 16:10:46 2017 Robin MILAS
*/

int	my_strcmp(char *s1, char *s2)
{
  int	index;

  index = 0;
  while (s1[index] == s2[index])
    {
      if (s1[index] == '\0')
	{
	  return (0);
	}
      index = index + 1;
    }
  return (s1[index] - s2[index]);
}
