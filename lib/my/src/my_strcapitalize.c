#include	<stdio.h>

char	*my_strcapitalize(char *str)
{
  int   x;

  x = 0;
  if (str == NULL)
    return (NULL);
  while (str[x])
    {
      if (str[x] >= 'A' && str[x] <= 'Z')
        str[x] = str[x] + 32;
      x++;
    }
  x = 1;
  if (str[0] >= 'a' && str[0] <= 'z')
    str[0] = str[0] - 32;
  while (str[x])
    {
      if ((str[x] >= ' ' && str[x] <= '/') || (str[x] <= '@' && str[x] >= ':'))
        if (str[x + 1] >= 'a' && str[x + 1] <= 'z')
          str[x + 1] -= 32;
      x++;
    }
  return (str);
}
