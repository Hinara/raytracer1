/*
** my_str_to_wordtab.c for minishell1 in /home/robin.milas/Current/PSU_2016_minishell1
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Jan 19 16:13:34 2017 Robin MILAS
** Last update Thu Jan 19 18:24:29 2017 Robin MILAS
*/

#include <stdlib.h>

char	is_alphanum(char c)
{
  if (c == ' ' || c == '\0' || c == '\n' || c == '\t')
    return (0);
  return (1);
}

int	calculate_words(char *str)
{
  int	index;
  int	count;

  index = 0;
  count = 1;
  while (str[index] != '\0')
    {
      if (!is_alphanum(str[index]))
	{
	  if (index > 0)
	    {
	      if (is_alphanum(str[index - 1]) && str[index + 1] != '\0')
		{
		  count = count + 1;
		}
	    }
	}
      index = index + 1;
    }
  return (count);
}

int	calculate_word_length(char *str, int *from)
{
  int	i;

  i = *from;
  while (!is_alphanum(str[i]))
    {
      i = i + 1;
      if (str[i] == '\0')
	{
	  return (-1);
	}
    }
  *from = i;
  while (is_alphanum(str[i]))
  {
      i = i + 1;
  }
  return (i);
}

void	populate_pointers(char **wordtab, char *str, int index, int from)
{
  int	i;

  i = calculate_word_length(str, &from);
  if (i < 0)
    {
      return ;
    }
  wordtab[index] = malloc(((i - from) + 1) * sizeof(char));
  i = from;
  while (is_alphanum(str[i]))
    {
      wordtab[index][i - from] = str[i];
      i = i + 1;
    }
  wordtab[index][i - from] = '\0';
  if (str[i] == '\0')
    {
      wordtab[index + 1] = 0;
    }
  else
    {
      populate_pointers(wordtab, str, index + 1, i);
    }
  return ;
}

char	**my_str_to_wordtab(char *str)
{
  char	**wordtab;

  if (*str == *"")
    {
      wordtab = malloc(sizeof(char *));
      wordtab[0] = 0;
      return (wordtab);
    }
  wordtab = malloc((calculate_words(str) + 1) * sizeof(char *));
  populate_pointers(wordtab, str, 0, 0);
  return (wordtab);
}
