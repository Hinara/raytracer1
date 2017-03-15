/*
** create_objs.c for writer in /home/milasr/Current/raytracer1/writer/src
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sat Mar 11 16:24:42 2017 Milas Robin
** Last update Mon Mar 13 16:42:07 2017 Milas Robin
*/

static inline char	is_number(char c)
{
  return (c >= '0' && c <= '9');
}

static int	get_floating_part(char **str, float *res)
{
  double	decimal_multiplicator;

  *str += 1;
  if (!is_number(**str))
    return (-1);
  decimal_multiplicator = 0.1;
  while (is_number(**str) && decimal_multiplicator != 0.0)
    {
      *res = *res + (**str - '0') * decimal_multiplicator;
      decimal_multiplicator /= 10.0;
      *str += 1;
    }
  return (0);
}

static int	get_float_number_sign(char **str)
{
  if (**str == '-')
    {
      *str += 1;
      return (-1);
    }
  if (**str == '+')
    *str += 1;
  return (1);
}

char		get_float(char *str, void *res_v)
{
  float *tmp;
  float res;
  char	neg;

  tmp = res_v;
  res = 0.0f;
  neg = get_float_number_sign(&str);
  if (!is_number(*str))
    return (-1);
  while (is_number(*str))
    {
      res = res * 10.0f + (*str - '0');
      str += 1;
    }
  if (*str == '.')
    {
      if (get_floating_part(&str, &res) < 0)
	return (-1);
    }
  if (*str != '\0')
    return (-1);
  if (neg < 0)
    res = -res;
  *tmp = res;
  return (0);
}
