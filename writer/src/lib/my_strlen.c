/*
** my_strlen.c for minishell1 in /home/robin.milas/Current/PSU_2016_minishell1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Jan 19 16:10:57 2017 Robin MILAS
** Last update Thu Jan 19 16:10:59 2017 Robin MILAS
*/
int	my_strlen(char *str)
{
  int	nb;

  nb = 0;
  while (*str != '\0')
    {
      nb = nb + 1;
      str = str + sizeof(char);
    }
  return (nb);
}
