#include	<stdio.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (src == NULL || dest == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
