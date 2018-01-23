#include	<stdio.h>

int	mstrlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  if (to_find == NULL)
    return (str);
  while (*str)
    {
      while (str[i] == to_find[i])
        i++;
      if (i == mstrlen(to_find))
	return (str);
      str++;
    }
  return (NULL);
}
