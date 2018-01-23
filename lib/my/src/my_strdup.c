#include	<stdlib.h>
#include	<stdio.h>

char	*my_strdup(char *src)
{
  int   i;
  int   k;
  char  *dest;

  if (src == NULL)
    return (NULL);
  k = my_strlen(src);
  if ((dest = malloc(k * sizeof(char) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
